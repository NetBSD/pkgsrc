# $NetBSD: Makefile,v 1.5 2016/03/05 11:29:13 jperkin Exp $

DISTNAME=	uftp-4.1.2
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://sourceforge.net/projects/uftp-multicast/files/source-tar/
EXTRACT_SUFX=	.tar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://uftp-multicast.sourceforge.net/
COMMENT=	UFTP is an encrypted multicast file transfer program
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake
NO_CONFIGURE=	yes
MAKE_FILE=	makefile

INSTALLATION_DIRS+=	bin sbin ${PKGMANDIR}/man1

MAKE_ENV+=	LIB="${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib"

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
