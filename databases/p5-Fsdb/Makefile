# $NetBSD: Makefile,v 1.17 2019/08/11 13:18:30 wiz Exp $

DISTNAME=	Fsdb-2.65
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	http://www.isi.edu/~johnh/SOFTWARE/FSDB/

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	http://www.isi.edu/~johnh/SOFTWARE/FSDB/index.html
COMMENT=	Commands for manipulating flat-ASCII databases
LICENSE=	gnu-gpl-v2

CONFLICTS=	jdb-[0-9]*

USE_TOOLS+=	groff perl

DEPENDS+=	p5-HTML-Parser>=3.69:../../www/p5-HTML-Parser
DEPENDS+=	p5-Text-CSV_XS>=0.91:../../textproc/p5-Text-CSV_XS
DEPENDS+=	p5-XML-Simple-[0-9]*:../../textproc/p5-XML-Simple

PERL5_PACKLIST=		auto/Fsdb/.packlist

REPLACE_PERL+=	lib/Fsdb.pm
REPLACE_PERL+=	lib/Fsdb/Filter.pm
REPLACE_PERL+=	lib/Fsdb/Filter/cgi_to_db.pm
REPLACE_PERL+=	lib/Fsdb/Filter/combined_log_format_to_db.pm
REPLACE_PERL+=	lib/Fsdb/Filter/csv_to_db.pm
REPLACE_PERL+=	lib/Fsdb/Filter/db_to_csv.pm
REPLACE_PERL+=	lib/Fsdb/Filter/db_to_html_table.pm
REPLACE_PERL+=	lib/Fsdb/Filter/dbcol.pm
REPLACE_PERL+=	lib/Fsdb/Filter/dbcolcopylast.pm
REPLACE_PERL+=	lib/Fsdb/Filter/dbcolcreate.pm
REPLACE_PERL+=	lib/Fsdb/Filter/dbcoldefine.pm
REPLACE_PERL+=	lib/Fsdb/Filter/dbcolhisto.pm
REPLACE_PERL+=	lib/Fsdb/Filter/dbcolmerge.pm
REPLACE_PERL+=	lib/Fsdb/Filter/dbcolmovingstats.pm
REPLACE_PERL+=	lib/Fsdb/Filter/dbcolneaten.pm
REPLACE_PERL+=	lib/Fsdb/Filter/dbcolpercentile.pm
REPLACE_PERL+=	lib/Fsdb/Filter/dbcolrename.pm
REPLACE_PERL+=	lib/Fsdb/Filter/dbcolscorrelate.pm
REPLACE_PERL+=	lib/Fsdb/Filter/dbcolsplittocols.pm
REPLACE_PERL+=	lib/Fsdb/Filter/dbcolsplittorows.pm
REPLACE_PERL+=	lib/Fsdb/Filter/dbcolsregression.pm
REPLACE_PERL+=	lib/Fsdb/Filter/dbcolstats.pm
REPLACE_PERL+=	lib/Fsdb/Filter/dbcolstatscores.pm
REPLACE_PERL+=	lib/Fsdb/Filter/dbfilealter.pm
REPLACE_PERL+=	lib/Fsdb/Filter/dbfilecat.pm
REPLACE_PERL+=	lib/Fsdb/Filter/dbfilediff.pm
REPLACE_PERL+=	lib/Fsdb/Filter/dbfilepivot.pm
REPLACE_PERL+=	lib/Fsdb/Filter/dbfilestripcomments.pm
REPLACE_PERL+=	lib/Fsdb/Filter/dbfilevalidate.pm
REPLACE_PERL+=	lib/Fsdb/Filter/dbformmail.pm
REPLACE_PERL+=	lib/Fsdb/Filter/dbjoin.pm
REPLACE_PERL+=	lib/Fsdb/Filter/dbmapreduce.pm
REPLACE_PERL+=	lib/Fsdb/Filter/dbmerge.pm
REPLACE_PERL+=	lib/Fsdb/Filter/dbmerge2.pm
REPLACE_PERL+=	lib/Fsdb/Filter/dbmultistats.pm
REPLACE_PERL+=	lib/Fsdb/Filter/dbpipeline.pm
REPLACE_PERL+=	lib/Fsdb/Filter/dbrow.pm
REPLACE_PERL+=	lib/Fsdb/Filter/dbrowaccumulate.pm
REPLACE_PERL+=	lib/Fsdb/Filter/dbrowcount.pm
REPLACE_PERL+=	lib/Fsdb/Filter/dbrowdiff.pm
REPLACE_PERL+=	lib/Fsdb/Filter/dbroweval.pm
REPLACE_PERL+=	lib/Fsdb/Filter/dbrowuniq.pm
REPLACE_PERL+=	lib/Fsdb/Filter/dbrvstatdiff.pm
REPLACE_PERL+=	lib/Fsdb/Filter/dbsort.pm
REPLACE_PERL+=	lib/Fsdb/Filter/dbsubprocess.pm
REPLACE_PERL+=	lib/Fsdb/Filter/html_table_to_db.pm
REPLACE_PERL+=	lib/Fsdb/Filter/kitrace_to_db.pm
REPLACE_PERL+=	lib/Fsdb/Filter/tabdelim_to_db.pm
REPLACE_PERL+=	lib/Fsdb/Filter/tcpdump_to_db.pm
REPLACE_PERL+=	lib/Fsdb/Filter/xml_to_db.pm
REPLACE_PERL+=	lib/Fsdb/IO.pm
REPLACE_PERL+=	lib/Fsdb/IO/Reader.pm
REPLACE_PERL+=	lib/Fsdb/IO/Replayable.pm
REPLACE_PERL+=	lib/Fsdb/IO/Writer.pm
REPLACE_PERL+=	lib/Fsdb/Support.pm
REPLACE_PERL+=	lib/Fsdb/Support/DelayPassComments.pm
REPLACE_PERL+=	lib/Fsdb/Support/Freds.pm
REPLACE_PERL+=	lib/Fsdb/Support/NamedTmpfile.pm
REPLACE_PERL+=	lib/Fsdb/Support/OS.pm
REPLACE_PERL+=	lib/Fsdb/Support/TDistribution.pm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
