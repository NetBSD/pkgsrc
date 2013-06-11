# $NetBSD: Makefile,v 1.3 2013/06/11 13:54:19 ryoon Exp $
#

DISTNAME=	rt-4.0.13
PKGNAME=	${DISTNAME:S/rt/rt4/}
CATEGORIES=	devel
MASTER_SITES=	http://download.bestpractical.com/pub/rt/release/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.bestpractical.com/rt/
COMMENT=	Industrial-grade ticketing system
LICENSE=	gnu-gpl-v2

# Dependency info. from sbin/rt-test-dependencies
# Core dependencies
DEPENDS+=	p5-Class-Accessor>=0.34:../../devel/p5-Class-Accessor
DEPENDS+=	p5-DateTime>=0.44:../../time/p5-DateTime
DEPENDS+=	p5-DateTime-Locale>=0.40:../../time/p5-DateTime-Locale
DEPENDS+=	p5-Class-ReturnValue>=0.40:../../devel/p5-Class-ReturnValue
DEPENDS+=	p5-DBIx-SearchBuilder>=1.59:../../databases/p5-DBIx-SearchBuilder
DEPENDS+=	p5-Text-Template>=1.44:../../textproc/p5-Text-Template
DEPENDS+=	p5-File-ShareDir-[0-9]*:../../devel/p5-File-ShareDir
DEPENDS+=	p5-HTML-Quoted-[0-9]*:../../www/p5-HTML-Quoted
DEPENDS+=	p5-HTML-Scrubber>=0.08:../../www/p5-HTML-Scrubber
DEPENDS+=	p5-HTML-Tree-[0-9]*:../../www/p5-HTML-Tree
DEPENDS+=	p5-HTML-Format-[0-9]*:../../www/p5-HTML-Format
DEPENDS+=	p5-Log-Dispatch>=2.23:../../devel/p5-Log-Dispatch
DEPENDS+=	p5-Sys-Syslog>=0.16:../../sysutils/p5-Sys-Syslog
DEPENDS+=	p5-MIME-tools>=5.425:../../mail/p5-MIME-tools
DEPENDS+=	p5-MailTools>=1.57:../../mail/p5-MailTools
DEPENDS+=	p5-Locale-Maketext-Lexicon>=0.32:../../misc/p5-Locale-Maketext-Lexicon
DEPENDS+=	p5-Locale-Maketext-Fuzzy-[0-9]*:../../misc/p5-Locale-Maketext-Fuzzy
DEPENDS+=	p5-Email-Address-[0-9]*:../../mail/p5-Email-Address
DEPENDS+=	p5-Text-Wrapper-[0-9]*:../../textproc/p5-Text-Wrapper
DEPENDS+=	p5-Time-modules-[0-9]*:../../time/p5-Time-modules
DEPENDS+=	p5-Time-HiRes-[0-9]*:../../time/p5-Time-HiRes
DEPENDS+=	p5-File-Temp>=0.19:../../devel/p5-File-Temp
DEPENDS+=	p5-Text-Quoted>=2.02:../../textproc/p5-Text-Quoted
DEPENDS+=	p5-Tree-Simple>=1.04:../../devel/p5-Tree-Simple
DEPENDS+=	p5-UNIVERSAL-require-[0-9]*:../../devel/p5-UNIVERSAL-require
DEPENDS+=	p5-Regexp-Common-[0-9]*:../../textproc/p5-Regexp-Common
DEPENDS+=	p5-Scalar-List-Utils-[0-9]*:../../devel/p5-Scalar-List-Utils
DEPENDS+=	p5-Module-Versions-Report>=1.05:../../devel/p5-Module-Versions-Report
DEPENDS+=	p5-Cache-Simple-TimedExpiry-[0-9]*:../../devel/p5-Cache-Simple-TimedExpiry
DEPENDS+=	p5-Encode>=2.39:../../textproc/p5-Encode
DEPENDS+=	p5-CSS-Squish>=0.06:../../www/p5-CSS-Squish
# File::Glob is a part of perl base.
DEPENDS+=	p5-Devel-StackTrace>=1.19:../../devel/p5-Devel-StackTrace
DEPENDS+=	p5-Text-Password-Pronounceable-[0-9]*:../../security/p5-Text-Password-Pronounceable
DEPENDS+=	p5-Devel-GlobalDestruction-[0-9]*:../../devel/p5-Devel-GlobalDestruction
DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Net-CIDR-[0-9]*:../../devel/p5-Net-CIDR
DEPENDS+=	p5-Regexp-Common-net-CIDR-[0-9]*:../../net/p5-Regexp-Common-net-CIDR
DEPENDS+=	p5-Regexp-IPv6-[0-9]*:../../net/p5-Regexp-IPv6

# Mason dependencies
DEPENDS+=	p5-HTML-Mason>=1.43:../../www/p5-HTML-Mason
# Errno is a part of perl base.
DEPENDS+=	p5-Digest-MD5>=2.27:../../security/p5-Digest-MD5
DEPENDS+=	p5-CGI>=1.20:../../www/p5-CGI
DEPENDS+=	p5-Storable>=2.08:../../devel/p5-Storable
DEPENDS+=	p5-Apache-Session>=1.53:../../www/p5-Apache-Session
DEPENDS+=	p5-XML-RSS>=1.05:../../textproc/p5-XML-RSS
DEPENDS+=	p5-Text-WikiFormat>=0.76:../../textproc/p5-Text-WikiFormat
DEPENDS+=	p5-JSON-[0-9]*:../../converters/p5-JSON
DEPENDS+=	p5-IPC-Run3-[0-9]*:../../devel/p5-IPC-Run3

# PSGI dependencies
DEPENDS+=	p5-CGI-PSGI-[0-9]*:../../www/p5-CGI-PSGI
DEPENDS+=	p5-HTML-Mason-PSGIHandler>=0.52:../../www/p5-HTML-Mason-PSGIHandler
DEPENDS+=	p5-Plack>=0.9971:../../www/p5-Plack
DEPENDS+=	p5-Starlet-[0-9]*:../../www/p5-Starlet
DEPENDS+=	p5-CGI-Emulate-PSGI-[0-9]*:../../www/p5-CGI-Emulate-PSGI
DEPENDS+=	p5-CGI-Emulate-PSGI-[0-9]*:../../www/p5-CGI-Emulate-PSGI

# Mailgate dependencies
DEPENDS+=	p5-Getopt-Long-[0-9]*:../../devel/p5-Getopt-Long
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-Pod-Usage-[0-9]*:../../devel/p5-Pod-Usage

# SSL-Mailgate dependencies
DEPENDS+=	p5-Crypt-SSLeay-[0-9]*:../../security/p5-Crypt-SSLeay
DEPENDS+=	p5-LWP-Protocol-https-[0-9]*:../../www/p5-LWP-Protocol-https
DEPENDS+=	p5-Mozilla-CA-[0-9]*:../../security/p5-Mozilla-CA

# CLI dependencies
DEPENDS+=	p5-HTTP-Message-[0-9]*:../../www/p5-HTTP-Message
# Text::ParseWords is a part of perl base.
# Term::ReadLine is a part of perl base.
DEPENDS+=	p5-Term-ReadKey-[0-9]*:../../devel/p5-Term-ReadKey

# Dev dependencies
#DEPENDS+=	p5-Email-Abstract-[0-9]*:../../mail/p5-Email-Abstract
#DEPENDS+=	p5-Test-Email-[0-9]*:../../mail/p5-Test-Email
#DEPENDS+=	p5-HTML-Form-[0-9]*:../../www/p5-HTML-Form
#DEPENDS+=	p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser
#DEPENDS+=	p5-WWW-Mechanize>=1.52:../../www/p5-WWW-Mechanize
#DEPENDS+=	p5-Test-WWW-Mechanize>=1.30:../../www/p5-Test-WWW-Mechanize
#DEPENDS+=	p5-Module-Refresh>=0.03:../../devel/p5-Module-Refresh
#DEPENDS+=	p5-Test-Expect>=0.31:../../devel/p5-Test-Expect
#DEPENDS+=	p5-XML-Simple-[0-9]*:../../textproc/p5-XML-Simple
#DEPENDS+=	p5-XML-Simple-[0-9]*:../../textproc/p5-XML-Simple
# File::Find is a part of perl base.
#DEPENDS+=	p5-Test-Deep>=0:../../devel/p5-Test-Deep
#DEPENDS+=	p5-String-ShellQuote-[0-9]*:../../textproc/p5-String-ShellQuote
#DEPENDS+=	p5-Log-Dispatch-Perl-[0-9]*:../../devel/p5-Log-Dispatch-Perl
#DEPENDS+=	p5-Test-Warn-[0-9]*:../../devel/p5-Test-Warn
#DEPENDS+=	p5-Test-Simple>=0.90:../../devel/p5-Test-Simple
#DEPENDS+=	p5-Test-MockTime-[0-9]*:../../time/p5-Test-MockTime
#DEPENDS+=	p5-Test-WWW-Mechanize-PSGI-[0-9]*:../../www/p5-Test-WWW-Mechanize-PSGI
#DEPENDS+=	p5-Plack-Middleware-Test-StashWarnings-[0-9]*:../../www/p5-Plack-Middleware-Test-StashWarnings
#DEPENDS+=	p5-Test-LongString-[0-9]*:../../devel/p5-Test-LongString
#DEPENDS+=	p5-Test-NoWarnings-[0-9]*:../../devel/p5-Test-NoWarnings

# GPG dependencies
DEPENDS+=	p5-GnuPG-Interface-[0-9]*:../../security/p5-GnuPG-Interface
DEPENDS+=	p5-PerlIO-eol-[0-9]*:../../devel/p5-PerlIO-eol

# ICAL dependency
DEPENDS+=	p5-Data-ICal-[0-9]*:../../time/p5-Data-ICal

# SMTP dependency
DEPENDS+=	p5-Net-[0-9]*:../../net/p5-Net

# DASHBOARD dependencies
DEPENDS+=	p5-HTML-RewriteAttributes>=0.05:../../www/p5-HTML-RewriteAttributes
DEPENDS+=	p5-MIME-Types-[0-9]*:../../mail/p5-MIME-Types
DEPENDS+=	p5-URI>=1.59:../../www/p5-URI

# GRAPHVIS dependencies
#DEPENDS+=	p5-GraphViz-[0-9]*:../../graphics/p5-GraphViz
#DEPENDS+=	p5-IPC-Run>=0.90:../../devel/p5-IPC-Run

# GD dependencies
DEPENDS+=	p5-GD-[0-9]*:../../graphics/p5-GD
DEPENDS+=	p5-GDGraph-[0-9]*:../../graphics/p5-GDGraph
DEPENDS+=	p5-GDTextUtil-[0-9]*:../../graphics/p5-GDTextUtil

# USERLOGO dependency
DEPENDS+=	p5-Convert-Color-[0-9]*:../../converters/p5-Convert-Color

# HTML-DOC dependency
DEPENDS+=	p5-Pod-Simple-[0-9]*:../../textproc/p5-Pod-Simple

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
