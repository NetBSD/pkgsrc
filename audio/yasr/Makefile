# $NetBSD: Makefile,v 1.1 2024/03/11 07:52:38 wiz Exp $

COMMITS=	144
DISTNAME=	yasr-0.0.0.${COMMITS}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=mgorse/}
GITHUB_TAG=	f60db19350542e6f4b7d268a310b9f2b9f3076c0

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mgorse/yasr
COMMENT=	Lightweight and portable screen reader
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c
USE_TOOLS=	pkg-config msgfmt xgettext

# Replace bash with sh in configuration example
SUBST_CLASSES+=		use-sh
SUBST_STAGE.use-sh=	pre-configure
SUBST_MESSAGE.use-sh=	Use sh instead of bash
SUBST_FILES.use-sh=	yasr/yasr.conf
SUBST_SED.use-sh=	-e 's,/bin/bash,/bin/sh,'

# Fix eflite path in configuration example
SUBST_CLASSES+=			fix-eflite
SUBST_STAGE.fix-eflite=		pre-configure
SUBST_MESSAGE.fix-eflite=	Fix eflite path
SUBST_FILES.fix-eflite=		yasr/yasr.conf
SUBST_SED.fix-eflite=		-e 's,/usr/local/bin/eflite,${PREFIX}/bin/eflite,'

.include "../../devel/meson/build.mk"
.include "../../audio/speech-dispatcher/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
