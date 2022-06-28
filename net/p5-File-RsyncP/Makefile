# $NetBSD: Makefile,v 1.11 2022/06/28 11:35:05 wiz Exp $

DISTNAME=	File-RsyncP-0.76
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/C/CB/CBARRATT/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/File-RsyncP
COMMENT=	Perl Rsync client
LICENSE=	gnu-gpl-v3

MAKE_JOBS_SAFE=		no
USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/File/RsyncP/.packlist
PERL5_MODULE_TYPE=	MakeMaker

REPLACE_PERL+=		lib/File/RsyncP.pm
REPLACE_PERL+=		lib/File/RsyncP/FileIO.pm
REPLACE_PERL+=		FileList/FileList.pm
REPLACE_PERL+=		Digest/Digest.pm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
