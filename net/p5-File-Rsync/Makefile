# $NetBSD: Makefile,v 1.8 2019/07/01 21:35:49 nia Exp $

DISTNAME=	File-Rsync-0.49
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../..//authors/id/L/LE/LEAKIN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/distribution/File-Rsync/Rsync.pm
COMMENT=	Perl module interface to rsync(1)
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	rsync-[0-9]*:../../net/rsync
DEPENDS+=	p5-IPC-Run3-[0-9]*:../../devel/p5-IPC-Run3
DEPENDS+=	p5-Data-Dumper-[0-9]*:../../devel/p5-Data-Dumper
DEPENDS+=	p5-Carp-[0-9]*:../../devel/p5-Carp

REPLACE_PERL+=		test.pl

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths
SUBST_FILES.fix-paths=		Rsync.pm
SUBST_VARS.fix-paths+=		PREFIX

PERL5_MODULE_TYPE=      MakeMaker
PERL5_PACKLIST=         auto/File/Rsync/.packlist

USE_LANGUAGES=          # none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
