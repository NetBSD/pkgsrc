# $NetBSD: Makefile,v 1.1.1.1 2003/02/11 12:30:28 lukem Exp $

DISTNAME=	roundup-0.5.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=roundup/}

MAINTAINER=	lukem@netbsd.org
HOMEPAGE=	http://roundup.sf.net/
COMMENT=	Issue tracking system with command-line, web and email clients

PYDISTUTILSPKG=	yes

PYTHON_PATCH_SCRIPTS=	roundup/admin.py roundup/backends/locking.py \
			roundup/version_check.py cgi-bin/roundup.cgi

ROUNDUPDOCDIR=	${LOCALBASE}/share/doc/roundup

post-install:
	${INSTALL_DATA_DIR} ${ROUNDUPDOCDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} CHANGES.txt COPYING.txt README.txt \
	    ${ROUNDUPDOCDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} *.txt *.html *.css ${ROUNDUPDOCDIR}
	${INSTALL_DATA_DIR} ${ROUNDUPDOCDIR}/images
	cd ${WRKSRC}/doc/images && ${INSTALL_DATA} *.png ${ROUNDUPDOCDIR}/images

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
