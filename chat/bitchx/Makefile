# $NetBSD: Makefile,v 1.65 2023/10/24 22:08:19 wiz Exp $

DISTNAME=	bitchx-1.2.1
PKGREVISION=	6
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bitchx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.bitchx.org/
COMMENT=	IRC client based on ircII
LICENSE=	modified-bsd

USE_TOOLS+=	bash

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=		YES

.if ${IPV6_READY:tl} == "yes"
CONFIGURE_ARGS+=	--enable-ipv6
.endif
CONFIGURE_ARGS+=	--with-ssl
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share
CONFIG_SHELL=		${TOOLS_PATH.bash}

CFLAGS.Darwin+=	-DBIND_8_COMPAT

SUBST_CLASSES+=		manpage
SUBST_STAGE.manpage=	pre-configure
SUBST_FILES.manpage+=	doc/BitchX.1
SUBST_SED.manpage=	-e 's,/usr/local,${PREFIX},g'

SUBST_CLASSES+=		ssl
SUBST_STAGE.ssl=	pre-configure
SUBST_FILES.ssl+=	configure
SUBST_SED.ssl=		-e 's|SSLeay|ERR_get_error|'

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/terminfo.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
