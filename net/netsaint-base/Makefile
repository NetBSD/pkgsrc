# $NetBSD: Makefile,v 1.10 2002/03/22 11:00:34 rh Exp $
#

DISTNAME=	netsaint-0.0.6
PKGNAME=	${DISTNAME:S/-/-base-/}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://netsaint.sourceforge.net/download/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.netsaint.org/
COMMENT=	network monitor

DEPENDS+=	gd>=1.8.4nb1:../../graphics/gd

USE_PERL5=	YES

.include "Makefile.common"

INSTALL_TARGET=	install install-config

post-configure:
	${SED} <${FILESDIR}/netsaint-setup.sh >${WRKDIR}/netsaint-setup.sh \
		-e 's:@@USER@@:${NETSAINT_USER}:g'			\
		-e 's:@@GROUP@@:${NETSAINT_GROUP}:g'

post-install:
	cd ${WRKDIR} && ${INSTALL_SCRIPT} netsaint-setup.sh ${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"
