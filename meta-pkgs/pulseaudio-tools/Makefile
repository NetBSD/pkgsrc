# $NetBSD: Makefile,v 1.3 2013/04/06 11:41:35 wiz Exp $
#

DISTNAME=	pulseaudio-tools-1.0
CATEGORIES=	meta-pkgs audio
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pulseaudio.org/
COMMENT=	Management tools for PulseAudio

DEPENDS+=	paman-[0-9]*:../../audio/paman
DEPENDS+=	paprefs-[0-9]*:../../audio/paprefs
DEPENDS+=	pavucontrol-[0-9]*:../../audio/pavucontrol
DEPENDS+=	pavumeter-[0-9]*:../../audio/pavumeter

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
