# $NetBSD: Makefile,v 1.5 1998/04/15 10:38:49 agc Exp $
# FreeBSD Id: Makefile,v 1.3 1997/01/06 12:13:36 jkh Exp
#

DISTNAME=       rtty-3.2
CATEGORIES=	sysutils
MASTER_SITES=   ftp://ftp.vix.com/pub/vixie/

MAINTAINER=	packages@netbsd.org

NO_WRKSUBDIR=   yes

OPSYS!=		uname -s

.if (${OPSYS} == "NetBSD")
pre-configure:
	for f in `find ${WRKDIR} -type f -print|xargs ${GREP} -l '/usr/local'`; do \
		${SED} -e 's:/usr/local:'${PREFIX}':g' < $$f > $$f.pdone && ${MV} $$f.pdone $$f; \
	done
.endif

.include "../../mk/bsd.pkg.mk"
