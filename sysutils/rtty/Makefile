# $NetBSD: Makefile,v 1.7 1999/04/09 00:55:22 hubertf Exp $
# FreeBSD Id: Makefile,v 1.3 1997/01/06 12:13:36 jkh Exp
#

DISTNAME=       rtty-3.2
CATEGORIES=	sysutils
MASTER_SITES=   ftp://ftp.vix.com/pub/vixie/

MAINTAINER=	packages@netbsd.org

NO_WRKSUBDIR=   yes

OPSYS!=		uname -s

pre-configure:
	for f in `find ${WRKDIR}/. -type f -print|xargs ${GREP} -l '/usr/local'`; do \
		echo patching $$f ; \
		${SED} -e 's:/usr/local:'${PREFIX}':g' < $$f > $$f.pdone && ${MV} $$f.pdone $$f; \
	done

.include "../../mk/bsd.pkg.mk"
