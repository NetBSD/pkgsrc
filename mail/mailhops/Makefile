# $NetBSD: Makefile,v 1.5 2013/04/06 03:45:16 rodent Exp $
#

DISTNAME=	mailhops-1.4
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.spinnaker.de/mutt/
EXTRACT_SUFX=		

LICENSE=	gnu-gpl-v2

MAINTAINER=	is@netbsd.org
HOMEPAGE=	http://www.spinnaker.de/mutt/
COMMENT=	Shows the route of an Internet mail message

WRKSRC=		${WRKDIR}
EXTRACT_CMD=	echo ${CP} "$${extract_file}" ${WRKSRC}/mailhops; \
				${CP} "$${extract_file}" ${WRKSRC}/mailhops


DEPENDS+=       	p5-TimeDate-[0-9]*:../../time/p5-TimeDate

USE_TOOLS+=     	perl:run

REPLACE_PERL+=  	mailhops

do-build:

do-configure:

do-install:
			${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/bin
			${INSTALL_SCRIPT} ${WRKSRC}/mailhops \
				${DESTDIR}${PREFIX}/bin


.include "../../mk/bsd.pkg.mk"

