# $NetBSD: Makefile,v 1.10 2019/08/11 13:22:47 wiz Exp $
#

DISTNAME=	log2timeline_${L2T_VERSION}
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	6
CATEGORIES=	security
MASTER_SITES=	http://log2timeline.googlecode.com/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://log2timeline.net/
COMMENT=	Framework for automatic creation of a super timeline
LICENSE=	gnu-gpl-v3

L2T_VERSION=	0.65

REPLACE_PERL=	lib/Log2t/BinRead.pm
REPLACE_PERL=	lib/Log2t/Common.pm
REPLACE_PERL=	lib/Log2t/Network.pm
REPLACE_PERL=	lib/Log2t/Numbers.pm
REPLACE_PERL=	lib/Log2t/Time.pm
REPLACE_PERL=	lib/Log2t/Win.pm
REPLACE_PERL=	lib/Log2t/WinReg.pm
REPLACE_PERL=	lib/Log2t/input/ff_cache.pm
REPLACE_PERL=	lib/Log2t/input/safari.pm
REPLACE_PERL=	l2t_process_old.pl

DEPENDS+=	p5-Archive-Zip>=1.18:../../archivers/p5-Archive-Zip
DEPENDS+=	p5-Carp-Assert>=0:../../devel/p5-Carp-Assert
DEPENDS+=	p5-DBD-SQLite>=0:../../databases/p5-DBD-SQLite
DEPENDS+=	p5-DBI>=1.52:../../databases/p5-DBI
DEPENDS+=	p5-Data-Hexify>=0:../../converters/p5-Data-Hexify
DEPENDS+=	p5-Date-Manip>=0:../../devel/p5-Date-Manip
DEPENDS+=	p5-DateTime>=0.41:../../time/p5-DateTime
DEPENDS+=	p5-DateTime-Format-Strptime>=0:../../time/p5-DateTime-Format-Strptime
DEPENDS+=	p5-DateTime-TimeZone>=0:../../time/p5-DateTime-TimeZone
DEPENDS+=	p5-Digest-CRC>=0.14:../../security/p5-Digest-CRC
#DEPENDS+=	{perl>=5.7.3,p5-Digest-MD5>=0}:../../security/p5-Digest-MD5
#DEPENDS+=	{perl>=5.7.3,p5-Encode>=0}:../../textproc/p5-Encode
DEPENDS+=	p5-File-Mork>=0.3:../../www/p5-File-Mork
#DEPENDS+=	{perl>=5,p5-Getopt-Long>=0}:../../devel/p5-Getopt-Long
DEPENDS+=	p5-HTML-Parser>=0:../../www/p5-HTML-Parser
DEPENDS+=	p5-HTML-Scrubber>=0:../../www/p5-HTML-Scrubber
DEPENDS+=	p5-Image-ExifTool>=0:../../graphics/p5-Image-ExifTool
DEPENDS+=	p5-Mac-PropertyList>=0:../../misc/p5-Mac-PropertyList
DEPENDS+=	p5-Net-Pcap>=0:../../net/p5-Net-Pcap
DEPENDS+=	p5-Params-Validate>=0:../../devel/p5-Params-Validate
DEPENDS+=	p5-Parse-Win32Registry>=0:../../misc/p5-Parse-Win32Registry
DEPENDS+=	p5-XML-LibXML>=0:../../textproc/p5-XML-LibXML
DEPENDS+=	p5-version>=0:../../devel/p5-version

PERL5_PACKLIST=	auto/Log2t/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
