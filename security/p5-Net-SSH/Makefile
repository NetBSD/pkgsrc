# $NetBSD: Makefile,v 1.23 2017/06/05 14:24:34 ryoon Exp $
#

DISTNAME=		Net-SSH-Perl-2.09.01
PKGNAME=		p5-${DISTNAME:C/-Perl//}
PKGREVISION=		1
CATEGORIES=		security net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Net-SSH-Perl/
COMMENT=		Perl implementations of SSH1 and SSH2 protocols
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Convert-PEM>=0.05:../../textproc/p5-Convert-PEM
DEPENDS+=		p5-CryptX-[0-9]*:../../security/p5-CryptX
DEPENDS+=		p5-Digest-BubbleBabble>=0.01:../../security/p5-Digest-BubbleBabble
DEPENDS+=		p5-Math-GMP>=1.04:../../math/p5-Math-GMP
DEPENDS+=		p5-String-CRC32>=1.2:../../textproc/p5-String-CRC32

PKG_OPTIONS_VAR=	PKG_OPTIONS.p5-Net-SSH
PKG_SUPPORTED_OPTIONS=	idea
#KG_SUGGESTED_OPTIONS=	idea

# Omit the last micro version, for example 2.09.01 -> 2.09
WRKSRC=			${WRKDIR}/${DISTNAME:C/([0-9]+)\.([0-9]+)[0-9.]+/\1.\2/}

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Midea)
DEPENDS+=		p5-Crypt-IDEA-[0-9]*:../../security/p5-Crypt-IDEA
.endif

PERL5_PACKLIST=		auto/Net/SSH/Perl/.packlist

# no prompt from ExtUtils::MakeMaker's prompt()
MAKE_ENV+=		PERL_MM_USE_DEFAULT=true

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
