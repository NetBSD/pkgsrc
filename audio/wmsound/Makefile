# $NetBSD: Makefile,v 1.6 2000/12/12 02:10:18 wiz Exp $

DISTNAME=	wmsound-0.9.4
CATEGORIES=	audio x11
MASTER_SITES=	http://www.frontiernet.net/~southgat/wmsound/download/ \
		ftp://shadowmere.student.utwente.nl/pub/WindowMaker/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} wmsdefault${EXTRACT_SUFX}

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://www.frontiernet.net/~southgat/wmsound/

DEPENDS+=	windowmaker-*:../../wm/windowmaker

USE_X11BASE=	yes
USE_IMAKE=	yes

post-extract:
	${SED} -e "s,@PREFIX@,${PREFIX},g" ${FILESDIR}/WMSound \
		>${WRKDIR}/WMSound

post-install:
	${INSTALL_DATA} ${WRKDIR}/WMSound ${PREFIX}/etc/WindowMaker
	( cd ${WRKDIR}/Sounds; \
	  for f in *; do \
		${INSTALL_DATA} "$$f" ${PREFIX}/share/WindowMaker/Sounds/; \
	  done )

.include "../../mk/bsd.pkg.mk"
