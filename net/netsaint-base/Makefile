# $NetBSD: Makefile,v 1.6 2002/01/31 17:24:38 jlam Exp $
#

DISTNAME=	netsaint-0.0.6
PKGNAME=	${DISTNAME:S/-/-base-/}
CATEGORIES=	net
MASTER_SITES=	http://netsaint.sourceforge.net/download/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.netsaint.org/
COMMENT=	network monitor

DEPENDS+=	gd>1.8.1:../../graphics/gd

USE_PERL5=	YES

.include "Makefile.common"

post-configure:
	${SED} <${FILESDIR}/netsaint-setup.sh >${WRKDIR}/netsaint-setup.sh \
		-e 's:@@USER@@:${NETSAINT_USER}:g'			\
		-e 's:@@GROUP@@:${NETSAINT_GROUP}:g'

post-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} install-config
	cd ${WRKDIR} && ${INSTALL_SCRIPT} netsaint-setup.sh ${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"
