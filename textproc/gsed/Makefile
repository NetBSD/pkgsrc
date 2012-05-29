# $NetBSD: Makefile,v 1.39 2012/05/29 22:22:00 cheusov Exp $
#

DISTNAME=	sed-4.2.1
PKGNAME=	g${DISTNAME}
PKGREVISION=	3
CATEGORIES=	textproc editors
MASTER_SITES=	${MASTER_SITE_GNU:=sed/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/sed/sed.html
COMMENT=	GNU implementation of sed, the POSIX stream editor
LICENSE=	gnu-gpl-v3 AND gnu-fdl-v1.3

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
INFO_FILES=		YES
TEST_TARGET=		check

INSTALLATION_DIRS=	gnu/bin

# at least Solaris-2.9 has issues with grep/egrep
USE_TOOLS+=		grep makeinfo

CONFIGURE_ARGS+=	--program-prefix=g

post-install:
	ln -f -s ../../bin/gsed ${DESTDIR}${PREFIX}/gnu/bin/sed

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
