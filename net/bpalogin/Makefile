# $NetBSD: Makefile,v 1.1.1.1 2002/04/12 08:20:32 rh Exp $
#

DISTNAME=	bpalogin-2.0.1-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bpalogin/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://bpalogin.sourceforge.net/
COMMENT=	BigPond Advance login client

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

ALL_TARGET=	bpalogin

pre-install:
	${SED} ${FILES_SUBST_SED} ${FILESDIR}/bpalogin			\
		> ${WRKDIR}/bpalogin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bpalogin ${PREFIX}/sbin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/bpalogin
	${INSTALL_DATA} ${WRKSRC}/bpalogin.conf				\
		${PREFIX}/share/examples/bpalogin
	${INSTALL_SCRIPT} ${WRKDIR}/bpalogin ${PREFIX}/etc/rc.d

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
