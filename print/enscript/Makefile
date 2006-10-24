# $NetBSD: Makefile,v 1.41 2006/10/24 15:39:18 obache Exp $
#

DISTNAME=		enscript-1.6.3
PKGREVISION=		4
CATEGORIES=		print
MASTER_SITES=		http://www.iki.fi/mtr/genscript/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.codento.com/people/mtr/genscript/
COMMENT=		ASCII-to-PostScript filter

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake lex perl:run xgettext
BROKEN_GETTEXT_DETECTION=	yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
INFO_FILES=		# PLIST

EGDIR=			${PREFIX}/share/examples/enscript
CONF_FILES=		${EGDIR}/enscript.cfg ${PKG_SYSCONFDIR}/enscript.cfg
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} sysconfdir=${EGDIR:Q}

.include "../../mk/bsd.prefs.mk"

.if defined(PAPERSIZE)
CONFIGURE_ARGS+=	--with-media=${PAPERSIZE:Q}
.endif

.include "../../devel/gettext-lib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
