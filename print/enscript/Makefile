# $NetBSD: Makefile,v 1.55 2018/08/22 09:46:12 wiz Exp $
#

DISTNAME=		enscript-1.6.6
PKGREVISION=		4
CATEGORIES=		print
MASTER_SITES=		${MASTER_SITE_GNU:=enscript/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/enscript/
COMMENT=		ASCII-to-PostScript filter
LICENSE=		gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake lex:run perl:run xgettext
BROKEN_GETTEXT_DETECTION=	yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
INFO_FILES=		YES

EGDIR=			${PREFIX}/share/examples/enscript
CONF_FILES=		${EGDIR}/enscript.cfg ${PKG_SYSCONFDIR}/enscript.cfg
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} sysconfdir=${EGDIR}
MAKE_ENV+=		prefix=${PREFIX}
BUILD_DEFS+=		PAPERSIZE

INSTALLATION_DIRS+=	share/enscript/afm share/enscript/hl

.include "../../mk/bsd.prefs.mk"

.if defined(PAPERSIZE)
CONFIGURE_ARGS+=	--with-media=${PAPERSIZE:Q}
.endif

.include "../../devel/gettext-lib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
