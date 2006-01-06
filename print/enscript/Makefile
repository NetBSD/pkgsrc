# $NetBSD: Makefile,v 1.32 2006/01/06 02:48:55 reed Exp $
#

DISTNAME=		enscript-1.6.3
PKGREVISION=		2
CATEGORIES=		print
MASTER_SITES=		http://www.iki.fi/mtr/genscript/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://people.ssh.fi/mtr/genscript/
COMMENT=		ASCII-to-PostScript filter

DEPENDS+=		papersize-[0-9]*:../../print/papersize

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
INFO_FILES=		enscript.info

EGDIR=			${PREFIX}/share/examples/enscript
CONF_FILES=		${EGDIR}/enscript.cfg ${PKG_SYSCONFDIR}/enscript.cfg

.include "../../mk/bsd.prefs.mk"
.if defined(PAPERSIZE)
CONFIGURE_ARGS+=--with-media=${PAPERSIZE:Q}
.endif

.include "../../devel/gettext-lib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
