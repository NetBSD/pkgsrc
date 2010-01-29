# $NetBSD: Makefile,v 1.15 2010/01/29 17:59:06 joerg Exp $
#

DISTNAME=		fhist-1.16
CATEGORIES=		devel scm
MASTER_SITES=		http://fhist.sourceforge.net/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://fhist.sourceforge.net/
COMMENT=		File history and comparison tools

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gsoelim msgfmt yacc
GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES

CONFIGURE_ARGS+=	--with-nlsdir=${PREFIX}/${PKGLOCALEDIR}/locale
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/doc

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 share/doc/fhist/en/man1 \
			share/locale/en/LC_MESSAGES
INSTALL_MAKE_FLAGS+=	RPM_BUILD_ROOT=${DESTDIR}

TEST_TARGET=		sure

.include "../../devel/gettext-lib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
