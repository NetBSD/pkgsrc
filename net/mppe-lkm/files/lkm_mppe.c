/*	NetBSD	*/
/*
 * Copyright (c) 1999 Darrin B. Jewell
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *      This product includes software developed by Darrin B. Jewell
 * 4. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <sys/param.h>
#include <sys/systm.h>
#include <sys/conf.h>
#include <sys/exec.h>
#include <sys/lkm.h>

#include <sys/tty.h>
#include <sys/ttycom.h>

MOD_MISC("mppe");

extern struct compressor ppp_mppe;
extern struct compressor *ppp_compressors[];
extern int mppe_in_use;

int	mppe_lkmentry __P((struct lkm_table *, int, int));
int	mppe_lkm_load __P((struct lkm_table *, int));

int
mppe_lkm_load(lkmtp, cmd)
		struct lkm_table *lkmtp;
		int cmd;
{
	int i;
	for(i=0;i<7;i++) {
		if (ppp_compressors[i] == NULL) {
			ppp_compressors[i] = &ppp_mppe;
			ppp_compressors[i+1] = NULL;
			break;
		}
	}
	if (i==7) {
		printf("MPPE: no free compressor slots\n");
		return ENODEV;
	}

	printf("MPPE: loaded into ppp at slot %d\n",i);

	return 0;
}

int
mppe_lkm_unload(lkmtp, cmd)
		struct lkm_table *lkmtp;
		int cmd;
{
	int i;
	if (mppe_in_use) {
		printf("MPPE: cannot unload lkm while in use (count=%d)\n",
			mppe_in_use);
		return EBUSY;
	}
	for(i=0;ppp_compressors[i];i++) {
		if (ppp_compressors[i] == &ppp_mppe) break;
	}
	if (ppp_compressors[i] == NULL) {
		printf("MPPE: cannot find mppe in ppp compressor slots\n");
		return ENODEV;
	}
	printf("MPPE: unloaded from ppp at slot %d\n",i);
	do {
		ppp_compressors[i] = ppp_compressors[i+1];
	} while(ppp_compressors[i++]);

	return 0;
}

int
mppe_lkm_stat(lkmtp, cmd)
		struct lkm_table *lkmtp;
		int cmd;
{
	printf("MPPE: use count %d\n",mppe_in_use);
	return 0;
}

int
mppe_lkmentry(lkmtp, cmd, ver)
	struct lkm_table *lkmtp;
	int cmd, ver;
{
	DISPATCH(lkmtp, cmd, ver, mppe_lkm_load,mppe_lkm_unload,mppe_lkm_stat);
}
