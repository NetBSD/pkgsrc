# $NetBSD: Makefile,v 1.17 2026/08/04 20:28:50 wiz Exp $

DISTNAME=	dumpet-2.1
PKGREVISION=	14
CATEGORIES=	devel
#MASTER_SITES=	https://fedorahosted.org/releases/d/u/dumpet/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	nonakap@gmail.com
HOMEPAGE=	https://github.com/rhboot/dumpet/
COMMENT=	Dump information about bootable CDs and other similar formats
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake pkg-config

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../devel/popt/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
