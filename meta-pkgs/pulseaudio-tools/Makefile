# $NetBSD: Makefile,v 1.1.1.1 2008/12/29 16:02:44 ahoka Exp $
#

DISTNAME=	pulsaudio-tools-0.9
CATEGORIES=	meta-pkgs audio
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pulseaudio.org/
COMMENT=	Management tools for PulseAudio

DEPENDS+=	paman-[0-9]*:../../audio/paman
DEPENDS+=	paprefs-[0-9]*:../../audio/paprefs
DEPENDS+=	padevchooser-[0-9]*:../../audio/padevchooser
DEPENDS+=	pavucontrol-[0-9]*:../../audio/pavucontrol
DEPENDS+=	pavumeter-[0-9]*:../../audio/pavumeter

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
