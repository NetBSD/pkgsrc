# $NetBSD: Makefile,v 1.7 2011/08/12 07:27:10 adam Exp $

DISTNAME=	Devel-Events-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/N/NU/NUFFIN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-Events/
COMMENT=	Perl 5 module providing an extensible instrumentation framework
LICENSE=	mit OR ${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Devel/Events/.packlist

BUILD_DEPENDS+=	p5-Test-use-ok-[0-9]*:../../devel/p5-Test-use-ok
DEPENDS+=	p5-Moose>=0.33:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-AttributeHelpers>=0.03:../../devel/p5-MooseX-AttributeHelpers
DEPENDS+=	p5-Set-Object-[0-9]*:../../devel/p5-Set-Object
DEPENDS+=	{perl>=5.10,p5-Time-HiRes-[0-9]*}:../../time/p5-Time-HiRes

CHECK_INTERPRETER_SKIP+=	${PERL5_INSTALLVENDORLIB:S|^${PREFIX}/||}/Devel/Events.pm
CHECK_INTERPRETER_SKIP+=	${PERL5_INSTALLVENDORLIB:S|^${PREFIX}/||}/Devel/Events/*

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
