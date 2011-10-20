# $NetBSD: Makefile,v 1.7 2011/10/20 01:03:47 hiramatsu Exp $

DISTNAME=	SSH-Batch-0.028
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	sysutils net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AG/AGENT/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/SSH-Batch/
COMMENT=	Cluster operations based on parallel SSH, set and interval arithmetic
LICENSE=	original-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/SSH/Batch/.packlist
PERL5_MODULE_TYPE=	Module::Install

REPLACE_PERL+=	bin/atnodes
REPLACE_PERL+=	bin/fornodes
REPLACE_PERL+=	bin/key2nodes
REPLACE_PERL+=	bin/tonodes

DEPENDS+=	p5-File-HomeDir-[0-9]*:../../devel/p5-File-HomeDir
DEPENDS+=	p5-IO-tty-[0-9]*:../../devel/p5-IO-Tty
DEPENDS+=	p5-Net-OpenSSH>=0.34:../../security/p5-Net-OpenSSH
DEPENDS+=	p5-Set-Scalar>=1.23:../../devel/p5-Set-Scalar
DEPENDS+=	p5-Term-ReadKey>=2.30:../../devel/p5-Term-ReadKey

BUILD_DEPENDS+=	p5-IPC-Run3-[0-9]*:../../devel/p5-IPC-Run3

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
