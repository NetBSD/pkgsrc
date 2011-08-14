# $NetBSD: Makefile,v 1.16 2011/08/14 08:18:11 obache Exp $

DISTNAME=	SQL-Translator-0.11006
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	databases perl5
#MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/J/JR/JROBINSON/}
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SQL/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/SQL-Translator/
COMMENT=	Manipulate structured data definitions (SQL and more)
LICENSE=	gnu-gpl-v2

DEPENDS+=	p5-Carp-Clan-[0-9]*:../../devel/p5-Carp-Clan
DEPENDS+=	p5-Class-Accessor-[0-9]*:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Class-Base-[0-9]*:../../devel/p5-Class-Base
DEPENDS+=	p5-Class-Data-Inheritable>=0.02:../../devel/p5-Class-Data-Inheritable
DEPENDS+=	p5-Class-MakeMethods-[0-9]*:../../devel/p5-Class-MakeMethods
DEPENDS+=	p5-Digest-SHA1>=2.0:../../security/p5-Digest-SHA1
DEPENDS+=	p5-File-ShareDir>=1.0:../../devel/p5-File-ShareDir
DEPENDS+=	p5-IO-stringy>=2.110:../../devel/p5-IO-stringy
DEPENDS+=	p5-Parse-RecDescent>=1.962.2:../../devel/p5-Parse-RecDescent
DEPENDS+=	p5-XML-Writer>=0.500:../../textproc/p5-XML-Writer

# Recommended
DEPENDS+=	p5-GD-[0-9]*:../../graphics/p5-GD
DEPENDS+=	p5-Graph-[0-9]*:../../devel/p5-Graph
DEPENDS+=	p5-GraphViz-[0-9]*:../../graphics/p5-GraphViz
DEPENDS+=	p5-Spreadsheet-ParseExcel>=0.41:../../math/p5-Spreadsheet-ParseExcel
DEPENDS+=	p5-Template-Toolkit>=2.10:../../www/p5-Template-Toolkit
DEPENDS+=	p5-Text-RecordParser>=0.02:../../textproc/p5-Text-RecordParser
DEPENDS+=	p5-XML-LibXML>=1.69:../../textproc/p5-XML-LibXML
DEPENDS+=	p5-YAML>=0.66:../../textproc/p5-YAML

BUILD_DEPENDS+=	{perl>=5.10,p5-PathTools-[0-9]*}:../../devel/p5-PathTools
BUILD_DEPENDS+=	p5-Test-Differences-[0-9]*:../../devel/p5-Test-Differences
BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception

USE_LANGUAGES=	# empty
PERL5_MODULE_TYPE= Module::Install
PERL5_PACKLIST=	auto/SQL/Translator/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

REPLACE_PERL+=	script/*

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
