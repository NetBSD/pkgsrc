# $NetBSD: Makefile,v 1.21 2022/09/26 10:21:32 nros Exp $
#

DISTNAME=		fhist-1.16
PKGREVISION=		1
CATEGORIES=		devel scm
MASTER_SITES=		http://fhist.sourceforge.net/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://fhist.sourceforge.net/
COMMENT=		File history and comparison tools
LICENSE=		gnu-gpl-v2

USE_TOOLS+=		gsoelim msgfmt yacc
GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
MAKE_JOBS_SAFE=		no

CONFIGURE_ARGS+=	--with-nlsdir=${PREFIX}/${PKGLOCALEDIR}/locale
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/doc

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 share/doc/fhist/en/man1 \
			share/locale/en/LC_MESSAGES
INSTALL_MAKE_FLAGS+=	RPM_BUILD_ROOT=${DESTDIR}

TEST_TARGET=		sure

.include "../../devel/gettext-lib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
