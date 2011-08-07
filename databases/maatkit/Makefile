# $NetBSD: Makefile,v 1.4 2011/08/07 02:16:03 mspo Exp $
#

DISTNAME=	maatkit-7540
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://maatkit.googlecode.com/files/

MAINTAINER=	msporleder@gmail.com
HOMEPAGE=	http://code.google.com/p/maatkit/downloads/
COMMENT=	Advanced command-line tools for open-source databases (MySQL)
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	perl
PKG_DESTDIR_SUPPORT=	user-destdir

REPLACE_PERL+=	bin/*

DEPENDS+=	p5-DBD-mysql-[0-9]*:../../databases/p5-DBD-mysql
DEPENDS+=	p5-Time-HiRes-[0-9]*:../../time/p5-Time-HiRes

PERL5_PACKLIST=	auto/maatkit/.packlist
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
