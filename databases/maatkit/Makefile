# $NetBSD: Makefile,v 1.8 2013/12/09 14:17:41 obache Exp $
#

DISTNAME=	maatkit-7540
PKGREVISION=	4
CATEGORIES=	databases
MASTER_SITES=	http://maatkit.googlecode.com/files/

MAINTAINER=	msporleder@gmail.com
HOMEPAGE=	http://code.google.com/p/maatkit/downloads/
COMMENT=	Advanced command-line tools for open-source databases (MySQL)
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	perl

REPLACE_PERL+=	bin/*

DEPENDS+=	p5-DBD-mysql-[0-9]*:../../databases/p5-DBD-mysql
DEPENDS+=	{perl>=5.7.3,p5-Time-HiRes-[0-9]*}:../../time/p5-Time-HiRes

PERL5_PACKLIST=	auto/maatkit/.packlist
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
