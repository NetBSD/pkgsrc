# $NetBSD: Makefile,v 1.1 2020/12/13 15:43:46 nia Exp $

DISTNAME=	cue2pops-linux-20180104
PKGNAME=	${DISTNAME:S/-linux//}
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_GITHUB:=makefu/}
GITHUB_PROJECT=	cue2pops-linux
GITHUB_TAG=	541863adf23fdecde92eba5899f8d58586ca4551

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/makefu/cue2pops-linux
COMMENT=	Convert BIN/CUE to VCD for POPS on the PS2

MAKE_FLAGS+=	INSTALL_DIR=${DESTDIR}${PREFIX}/bin

INSTALLATION_DIRS+=	bin

.include "../../mk/bsd.pkg.mk"
