# $NetBSD: Makefile,v 1.5 2017/06/05 14:24:16 ryoon Exp $

DISTNAME=	File-Rsync-0.49
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../..//authors/id/L/LE/LEAKIN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~leakin/File-Rsync/Rsync.pm
COMMENT=	Perl module interface to rsync(1)
LICENSE=	${PERL5_LICENSE}

DEPENDS+=		rsync-[0-9]*:../../net/rsync

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
