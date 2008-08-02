/*	$NetBSD: parse-config.c,v 1.1.2.4 2008/08/02 20:33:50 joerg Exp $	*/

#if HAVE_CONFIG_H
#include "config.h"
#endif
#include <nbcompat.h>
#if HAVE_SYS_CDEFS_H
#include <sys/cdefs.h>
#endif
#ifndef lint
__RCSID("$NetBSD: parse-config.c,v 1.1.2.4 2008/08/02 20:33:50 joerg Exp $");
#endif

/*-
 * Copyright (c) 2008 Joerg Sonnenberger <joerg@NetBSD.org>.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE
 * COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#if HAVE_ERR_H
#include <err.h>
#endif
#if HAVE_STRING_H
#include <string.h>
#endif

#include "lib.h"

const char     *config_file = SYSCONFDIR"/pkg_install.conf";

const char *cert_chain_file;
const char *certs_packages;
const char *certs_pkg_vulnerabilities;
const char *verified_installation;
const char *gpg_cmd;
const char *pkg_vulnerabilities_dir;
const char *pkg_vulnerabilities_file;
const char *pkg_vulnerabilities_url;
const char *ignore_advisories = NULL;

const char tnf_vulnerability_base[] = "ftp://ftp.NetBSD.org/pub/NetBSD/packages/vulns";

static struct config_variable {
	const char *name;
	const char **var;
} config_variables[] = {
	{ "CERTIFICATE_ANCHOR_PKGS", &certs_packages },
	{ "CERTIFICATE_ANCHOR_PKGVULN", &certs_pkg_vulnerabilities },
	{ "CERTIFICATE_CHAIN", &cert_chain_file },
	{ "GPG", &gpg_cmd },
	{ "PKGVULNDIR", &pkg_vulnerabilities_dir },
	{ "PKGVULNURL", &pkg_vulnerabilities_url },
	{ "IGNORE_URL", &ignore_advisories },
	{ "VERIFIED_INSTALLATION", &verified_installation },
	{ NULL, NULL }
};

void
pkg_install_config(void)
{
	char *value;
	struct config_variable *var;

	for (var = config_variables; var->name != NULL; ++var) {
		value = var_get(config_file, var->name);
		if (value != NULL)
			*var->var = value;
	}

	if (pkg_vulnerabilities_dir == NULL)
		pkg_vulnerabilities_dir = _pkgdb_getPKGDB_DIR();
	pkg_vulnerabilities_file = xasprintf("%s/pkg-vulnerabilities",
	    pkg_vulnerabilities_dir);
	if (pkg_vulnerabilities_url == NULL) {
		pkg_vulnerabilities_url = xasprintf("%s/pkg-vulnerabilities.gz",
		    tnf_vulnerability_base);
	}
	if (verified_installation == NULL)
		verified_installation = "never";
}

void
pkg_install_show_variable(const char *var_name)
{
	struct config_variable *var;

	for (var = config_variables; var->name != NULL; ++var) {
		if (strcmp(var->name, var_name) != 0)
			continue;
		if (*var->var != NULL)
			puts(*var->var);
	}
}
