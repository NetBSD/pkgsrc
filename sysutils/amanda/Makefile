# $NetBSD: Makefile,v 1.7 1998/04/20 11:56:26 frueauf Exp $
# FreeBSD Id: Makefile,v 1.9 1997/03/08 05:00:11 gpalmer Exp
#

DISTNAME=	amanda-2.3.0
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.cs.umd.edu/pub/amanda/

MAINTAINER=	packages@netbsd.org

PATCH_STRIP=
SCRIPTS_ENV+=	CFLAGS="${CFLAGS}"
MAN8=		amanda.8 amadmin.8 amcheck.8 amcleanup.8 amdump.8 \
		amflush.8 amlabel.8 amrestore.8  amtape.8

pre-configure:
	find ${WRKDIR} -type f -print|xargs ${GREP} -l '/usr/local' > ${WRKDIR}/prefix-list
	for f in `cat ${WRKDIR}/prefix-list`; do \
		${SED} -e 's:/usr/local:'${PREFIX}':g' < $$f > $$f.pdone && ${MV} $$f.pdone $$f; \
	done
	${RM} ${WRKDIR}/prefix-list

post-install:
	${MKDIR}  ${PREFIX}/share/examples/amanda
	${CP} -R ${WRKSRC}/example/* ${PREFIX}/share/examples/amanda

.include "../../mk/bsd.pkg.mk"
