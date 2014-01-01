# $NetBSD: Makefile,v 1.7 2014/01/01 03:31:50 ryoon Exp $

DISTNAME=	rt-4.2.1
PKGNAME=	${DISTNAME:S/rt/rt4/}
CATEGORIES=	devel
MASTER_SITES=	http://download.bestpractical.com/pub/rt/release/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.bestpractical.com/rt/
COMMENT=	Industrial-grade ticketing system
LICENSE=	gnu-gpl-v2

# Dependency info. from sbin/rt-test-dependencies
# Core dependencies
DEPENDS+=	p5-Apache-Session>=1.53:../../www/p5-Apache-Session
DEPENDS+=	{perl>=5.004,p5-CGI>=3.38}:../../www/p5-CGI
# CGI::Cookie is a part of p5-CGI.
DEPENDS+=	p5-CGI-Emulate-PSGI-[0-9]*:../../www/p5-CGI-Emulate-PSGI
DEPENDS+=	p5-CGI-PSGI-[0-9]*:../../www/p5-CGI-PSGI
DEPENDS+=	p5-Class-Accessor>=0.34:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Crypt-Eksblowfish-[0-9]*:../../security/p5-Crypt-Eksblowfish
DEPENDS+=	p5-Data-GUID-[0-9]*:../../devel/p5-Data-GUID
DEPENDS+=	p5-CSS-Squish>=0.06:../../www/p5-CSS-Squish
DEPENDS+=	p5-Date-Extract>=0.02:../../time/p5-Date-Extract
DEPENDS+=	p5-Date-Manip-[0-9]*:../../devel/p5-Date-Manip
DEPENDS+=	p5-DateTime>=0.44:../../time/p5-DateTime
DEPENDS+=	p5-DateTime-Format-Natural>0.67:../../time/p5-DateTime-Format-Natural
DEPENDS+=	p5-DateTime-Locale>=0.40:../../time/p5-DateTime-Locale
DEPENDS+=	p5-DBI-[0-9]*:../../databases/p5-DBI
DEPENDS+=	p5-DBIx-SearchBuilder>=1.65:../../databases/p5-DBIx-SearchBuilder
DEPENDS+=	p5-Devel-GlobalDestruction-[0-9]*:../../devel/p5-Devel-GlobalDestruction
DEPENDS+=	p5-Devel-StackTrace>=1.19:../../devel/p5-Devel-StackTrace
# Digest::base is a part of perl base.
DEPENDS+=	{perl>=5.8.1,p5-Digest-MD5>=2.27}:../../security/p5-Digest-MD5
DEPENDS+=	p5-Digest-SHA-[0-9]*:../../security/p5-Digest-SHA
DEPENDS+=	p5-Email-Address>=1.897:../../mail/p5-Email-Address
DEPENDS+=	p5-Email-Address-List-[0-9]*:../../mail/p5-Email-Address-List
DEPENDS+=	{perl>=5.11.3,p5-Encode>=2.39}:../../textproc/p5-Encode
# Errno is a part of perl base.
# File::Glob is a part of perl base.
DEPENDS+=	p5-File-ShareDir-[0-9]*:../../devel/p5-File-ShareDir
# File::Spec is a part of perl base.
DEPENDS+=	{perl>=5.10.1,p5-File-Temp>=0.19}:../../devel/p5-File-Temp
# HTML::Entities is a part of p5-HTML-Parser.
DEPENDS+=	p5-HTML-FormatText-WithLinks>=0.14:../../textproc/p5-HTML-FormatText-WithLinks
DEPENDS+=	p5-HTML-FormatText-WithLinks-AndTables-[0-9]*:../../textproc/p5-HTML-FormatText-WithLinks-AndTables
DEPENDS+=	p5-HTML-Mason-PSGIHandler>=0.52:../../www/p5-HTML-Mason-PSGIHandler
DEPENDS+=	p5-HTML-Quoted-[0-9]*:../../www/p5-HTML-Quoted
DEPENDS+=	p5-HTML-RewriteAttributes>=0.05:../../www/p5-HTML-RewriteAttributes
DEPENDS+=	p5-HTML-Scrubber>=0.08:../../www/p5-HTML-Scrubber
DEPENDS+=	p5-IPC-Run3-[0-9]*:../../devel/p5-IPC-Run3
DEPENDS+=	p5-JSON-[0-9]*:../../converters/p5-JSON
DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Locale-Maketext>=1.06:../../misc/p5-Locale-Maketext
DEPENDS+=	p5-Locale-Maketext-Fuzzy-[0-9]*:../../misc/p5-Locale-Maketext-Fuzzy
DEPENDS+=	p5-Locale-Maketext-Lexicon>=0.32:../../misc/p5-Locale-Maketext-Lexicon
DEPENDS+=	p5-Log-Dispatch>=2.30:../../devel/p5-Log-Dispatch
# Mail::Header is a part of p5-MailTools.
DEPENDS+=	p5-MailTools>=1.57:../../mail/p5-MailTools
# Mail::Mailer is a part of p5-MailTools.
DEPENDS+=	p5-MIME-tools>=5.504:../../mail/p5-MIME-tools
DEPENDS+=	p5-Module-Refresh>=0.03:../../devel/p5-Module-Refresh
DEPENDS+=	p5-Module-Versions-Report>=1.05:../../devel/p5-Module-Versions-Report
DEPENDS+=	p5-Net-CIDR-[0-9]*:../../devel/p5-Net-CIDR
DEPENDS+=	p5-Plack>=1.0002:../../www/p5-Plack
# Plack::Handler::Starlet is a part of p5-Startlet.
DEPENDS+=	p5-Starlet-[0-9]*:../../www/p5-Starlet
DEPENDS+=	p5-Regexp-Common-[0-9]*:../../textproc/p5-Regexp-Common
DEPENDS+=	p5-Regexp-Common-net-CIDR-[0-9]*:../../net/p5-Regexp-Common-net-CIDR
DEPENDS+=	p5-Regexp-IPv6-[0-9]*:../../net/p5-Regexp-IPv6
DEPENDS+=	p5-Role-Basic-[0-9]*:../../devel/p5-Role-Basic
# Scalar::Util is a part of p5-Scalar-List-Utils.
DEPENDS+=	p5-Scalar-List-Utils-[0-9]*:../../devel/p5-Scalar-List-Utils
DEPENDS+=	p5-Storable>=2.08:../../devel/p5-Storable
DEPENDS+=	p5-Symbol-Global-Name>=0.04:../../devel/p5-Symbol-Global-Name
DEPENDS+=	{perl>=5.8.9,p5-Sys-Syslog>=0.16}:../../sysutils/p5-Sys-Syslog
DEPENDS+=	p5-Text-Password-Pronounceable-[0-9]*:../../security/p5-Text-Password-Pronounceable
DEPENDS+=	p5-Text-Quoted>=2.02:../../textproc/p5-Text-Quoted
DEPENDS+=	p5-Text-Template>=1.44:../../textproc/p5-Text-Template
DEPENDS+=	p5-Text-WikiFormat>=0.76:../../textproc/p5-Text-WikiFormat
DEPENDS+=	p5-Text-Wrapper-[0-9]*:../../textproc/p5-Text-Wrapper
DEPENDS+=	{perl>=5.7.3,p5-Time-HiRes-[0-9]*}:../../time/p5-Time-HiRes
# Time::ParseDate is a part of p5-Time-modules.
DEPENDS+=	p5-Time-modules-[0-9]*:../../time/p5-Time-modules
DEPENDS+=	p5-Tree-Simple>=1.04:../../devel/p5-Tree-Simple
DEPENDS+=	p5-UNIVERSAL-require-[0-9]*:../../devel/p5-UNIVERSAL-require
DEPENDS+=	p5-XML-RSS>=1.05:../../textproc/p5-XML-RSS
DEPENDS+=	p5-HTML-Mason>=1.43:../../www/p5-HTML-Mason

# Mailgate dependencies
DEPENDS+=	p5-Crypt-SSLeay-[0-9]*:../../security/p5-Crypt-SSLeay
DEPENDS+=	{perl>=5,p5-Getopt-Long-[0-9]*}:../../devel/p5-Getopt-Long
DEPENDS+=	p5-LWP-Protocol-https-[0-9]*:../../www/p5-LWP-Protocol-https
# LWP::UserAgent is a part of p5-libwww.
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-Mozilla-CA-[0-9]*:../../security/p5-Mozilla-CA
# Net::SSL is a part of p5-Crypt-SSLeay.
DEPENDS+=	{perl>=5.6.0,p5-Pod-Usage-[0-9]*}:../../devel/p5-Pod-Usage

# CLI dependencies
# p5-Getopt-Long is duplicate with Mailgate dependencies.
# HTTP::Request::Common is a part of p5-HTTP-Message.
DEPENDS+=	p5-HTTP-Message-[0-9]*:../../www/p5-HTTP-Message
# LWP is a pert of perl base.
DEPENDS+=	p5-Term-ReadKey-[0-9]*:../../devel/p5-Term-ReadKey
# Term::ReadLine is a part of perl base.
# Text::ParseWords is a pert of perl base.

# Developer dependencies
# These are not used for normal use.

# DASHBOARD dependencies
DEPENDS+=	p5-URI>=1.59:../../www/p5-URI
DEPENDS+=	p5-MIME-Types-[0-9]*:../../mail/p5-MIME-Types
# URI::QueryParam is a part of p5-URI.

# GD dependencies
DEPENDS+=	p5-GD-[0-9]*:../../graphics/p5-GD
DEPENDS+=	p5-GDGraph-[0-9]*:../../graphics/p5-GDGraph
# GD::Text is a part of p5-GDTextUtil.
DEPENDS+=	p5-GDTextUtil-[0-9]*:../../graphics/p5-GDTextUtil

# GPG dependencies
DEPENDS+=	p5-File-Which-[0-9]*:../../devel/p5-File-Which
DEPENDS+=	p5-GnuPG-Interface-[0-9]*:../../security/p5-GnuPG-Interface
DEPENDS+=	p5-PerlIO-eol-[0-9]*:../../devel/p5-PerlIO-eol

# ICAL dependency
DEPENDS+=	p5-Data-ICal-[0-9]*:../../time/p5-Data-ICal

# SMIME dependencies
DEPENDS+=	p5-String-ShellQuote-[0-9]*:../../textproc/p5-String-ShellQuote
DEPENDS+=	p5-Crypt-X509-[0-9]*:../../security/p5-Crypt-X509
# File::Which is in GPG dependencies.

# USERLOGO dependency
# Module::Pluggable will be removed from the Perl core distribution...
DEPENDS+=	p5-Module-Pluggable-[0-9]*:../../devel/p5-Module-Pluggable
DEPENDS+=	p5-Convert-Color-[0-9]*:../../converters/p5-Convert-Color

.include "options.mk"

RT4DIR=		${PREFIX}/share/rt4

BUILD_DEFS+=	APACHE_GROUP APACHE_USER
FILES_SUBST+=	WWWGRP=${APACHE_GROUP} WWWOWN=${APACHE_USER} \
		RT4DIR=${RT4DIR}

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_MESSAGE.prefix=	Setting prefix.
SUBST_FILES.prefix=	config.layout
SUBST_VARS.prefix=	PREFIX PKG_SYSCONFDIR PKGMANDIR
SUBST_VARS.prefix+=	RT4DIR

GNU_CONFIGURE=	yes
NO_BUILD=	yes
USE_LANGUAGES=	c
USE_TOOLS+=	perl:run

USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS+=	--enable-layout=pkgsrc
CONFIGURE_ARGS+=	--with-db-type=${RT_DB_TYPE}
CONFIGURE_ARGS+=	--with-my-user-group

CONF_FILES_PERMS=	share/rt4/etc/RT_SiteConfig.pm.dist \
			share/rt4/etc/RT_SiteConfig.pm \
			${APACHE_USER} ${APACHE_GROUP} \
			640

post-install:
	mv ${DESTDIR}${PREFIX}/share/rt4/etc/RT_SiteConfig.pm \
		${DESTDIR}${PREFIX}/share/rt4/etc/RT_SiteConfig.pm.dist

.include "../../mk/bsd.pkg.mk"
