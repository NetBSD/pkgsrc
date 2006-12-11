# $NetBSD: Makefile,v 1.18 2006/12/11 16:26:39 wennmach Exp $

DISTNAME=		avrdude-5.2
#PKGREVISION=		1
CATEGORIES=		cross
MASTER_SITES=		http://download.savannah.gnu.org/releases/avrdude/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.bsdhome.com/avrdude/
COMMENT=		Downloader/uploader for Atmel AVR 8-bit RISC microcontrollers

USE_GNU_READLINE=	yes
TEX_DEPMETHOD=		build
TEX_ACCEPTED=		teTeX3

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=		yes
USE_TOOLS+=		makeinfo texi2html
INFO_FILES=		yes
EGDIR=			${PREFIX}/share/examples/avrdude
CONF_FILES=		${EGDIR}/avrdude.conf ${PKG_SYSCONFDIR}/avrdude.conf
CONF_FILES_PERMS=	${EGDIR}/avrdude.conf ${PKG_SYSCONFDIR}/avrdude.conf \
			${ROOT_USER} ${ROOT_GROUP} 644

CONFIGURE_ARGS+=	--enable-doc
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--egconfdir=${EGDIR:Q}
PLIST_SUBST+=		DISTNAME=${DISTNAME:Q}

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
