# $NetBSD: Makefile,v 1.12 2017/06/05 14:24:27 ryoon Exp $
#

DISTNAME=	Authen-PluggableCaptcha-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Authen/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Authen-PluggableCaptcha/
COMMENT=	Perl5 module implementing a pluggable Captcha framework
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Number-Spell>=0.04:../../textproc/p5-Number-Spell
DEPENDS+=	p5-HTML-Email-Obfuscate>=0.02:../../www/p5-HTML-Email-Obfuscate

REPLACE_PERL+=	lib/Authen/PluggableCaptcha/ErrorLoggingObject.pm
REPLACE_PERL+=	lib/Authen/PluggableCaptcha.pm
REPLACE_PERL+=	lib/Authen/PluggableCaptcha/Challenge.pm
REPLACE_PERL+=	lib/Authen/PluggableCaptcha/Challenge/DoMath.pm
REPLACE_PERL+=	lib/Authen/PluggableCaptcha/Challenge/TypeString.pm
REPLACE_PERL+=	lib/Authen/PluggableCaptcha/Helpers.pm
REPLACE_PERL+=	lib/Authen/PluggableCaptcha/KeyManager.pm
REPLACE_PERL+=	lib/Authen/PluggableCaptcha/Render.pm
REPLACE_PERL+=	lib/Authen/PluggableCaptcha/Render/Image.pm
REPLACE_PERL+=	lib/Authen/PluggableCaptcha/Render/Image/Imager.pm
REPLACE_PERL+=	lib/Authen/PluggableCaptcha/Render/Image/Imager/effects.pm
REPLACE_PERL+=	lib/Authen/PluggableCaptcha/Render/Image/Imager/effects/sinewarp.pm
REPLACE_PERL+=	lib/Authen/PluggableCaptcha/Render/Image/Imager/layers.pm
REPLACE_PERL+=	lib/Authen/PluggableCaptcha/Render/Image/Imager/layers/bg.pm
REPLACE_PERL+=	lib/Authen/PluggableCaptcha/Render/Image/Imager/layers/distraction_lines.pm
REPLACE_PERL+=	lib/Authen/PluggableCaptcha/Render/Image/Imager/layers/text.pm
REPLACE_PERL+=	lib/Authen/PluggableCaptcha/Render/Text.pm
REPLACE_PERL+=	lib/Authen/PluggableCaptcha/Render/Text/HTML.pm
REPLACE_PERL+=	lib/Authen/PluggableCaptcha/Render/Text/Plain.pm
REPLACE_PERL+=	lib/Authen/PluggableCaptcha/StandardAttributesObject.pm
REPLACE_PERL+=	lib/Authen/PluggableCaptcha/ValidityObject.pm

PERL5_PACKLIST=	auto/Authen/PluggableCaptcha/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
