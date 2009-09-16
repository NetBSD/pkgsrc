# $NetBSD: Makefile,v 1.37.2.1 2009/09/16 10:31:58 tron Exp $

DISTNAME=		rt-3.8.5
CATEGORIES=		devel
MASTER_SITES=		http://download.bestpractical.com/pub/rt/release/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://bestpractical.com/rt/
COMMENT=		Industrial-grade ticketing system
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	destdir

.include "options.mk"

USE_TOOLS+=	perl:run
USE_LANGUAGES+=	c

# Core dependencies:
DEPENDS+=	p5-Digest-[0-9]*:../../security/p5-Digest
DEPENDS+=	p5-Digest-MD5>=2.27:../../security/p5-Digest-MD5
DEPENDS+=	p5-DBI>=1.37:../../databases/p5-DBI
DEPENDS+=	p5-Class-ReturnValue>=0.40:../../devel/p5-Class-ReturnValue
DEPENDS+=	p5-TimeDate-[0-9]*:../../time/p5-TimeDate
DEPENDS+=	p5-DBIx-SearchBuilder>=1.54:../../databases/p5-DBIx-SearchBuilder
DEPENDS+=	p5-Text-Template>=1.43:../../textproc/p5-Text-Template
DEPENDS+=	p5-HTML-Parser>=3.35:../../www/p5-HTML-Parser
DEPENDS+=	p5-HTML-Scrubber>=0.08:../../www/p5-HTML-Scrubber
DEPENDS+=	p5-HTTP-Server-Simple>=0.34:../../www/p5-HTTP-Server-Simple
DEPENDS+=	p5-HTTP-Server-Simple-Mason>=0.09:../../www/p5-HTTP-Server-Simple-Mason
DEPENDS+=	p5-Log-Dispatch>=2.0:../../devel/p5-Log-Dispatch
DEPENDS+=	p5-Locale-Maketext>=1.06:../../misc/p5-Locale-Maketext
DEPENDS+=	p5-Locale-Maketext-Lexicon>=0.32:../../misc/p5-Locale-Maketext-Lexicon
DEPENDS+=	p5-Locale-Maketext-Fuzzy>=0.02:../../misc/p5-Locale-Maketext-Fuzzy
DEPENDS+=	p5-MIME-tools>=5.411.1:../../mail/p5-MIME-tools
DEPENDS+=	p5-MailTools>=1.57:../../mail/p5-MailTools
DEPENDS+=	p5-Email-Address-[0-9]*:../../mail/p5-Email-Address
DEPENDS+=	p5-Net>=1.15:../../net/p5-Net
DEPENDS+=	p5-Net-Server-[0-9]*:../../net/p5-Net-Server
DEPENDS+=	p5-Text-Wrapper>=1.0:../../textproc/p5-Text-Wrapper
DEPENDS+=	p5-Time-modules>=101.062101:../../time/p5-Time-modules
DEPENDS+=	p5-Text-Autoformat>=1.04:../../textproc/p5-Text-Autoformat
DEPENDS+=	p5-Text-Quoted>=2.02:../../textproc/p5-Text-Quoted
DEPENDS+=	p5-Tree-Simple>=1.04:../../devel/p5-Tree-Simple
DEPENDS+=	p5-Regexp-Common>=2.113:../../textproc/p5-Regexp-Common
DEPENDS+=	p5-Module-Versions-Report>=1.05:../../devel/p5-Module-Versions-Report
DEPENDS+=	p5-Cache-Simple-TimedExpiry-[0-9]*:../../devel/p5-Cache-Simple-TimedExpiry
DEPENDS+=	p5-UNIVERSAL-require>=0.11:../../devel/p5-UNIVERSAL-require
DEPENDS+=	p5-Calendar-Simple>=1.00:../../time/p5-Calendar-Simple
DEPENDS+=	p5-CSS-Squish>=0.07:../../www/p5-CSS-Squish
DEPENDS+=	p5-File-ShareDir>=1.00:../../devel/p5-File-ShareDir

# Mason dependencies:
DEPENDS+=	p5-HTML-Mason>=1.36:../../www/p5-HTML-Mason
DEPENDS+=	p5-Apache-Session>=1.53:../../www/p5-Apache-Session
DEPENDS+=	p5-XML-RSS>=1.05:../../textproc/p5-XML-RSS
DEPENDS+=	p5-GD-[0-9]*:../../graphics/p5-GD
DEPENDS+=	p5-GDGraph-[0-9]*:../../graphics/p5-GDGraph
DEPENDS+=	p5-GDTextUtil-[0-9]*:../../graphics/p5-GDTextUtil
DEPENDS+=	p5-Text-WikiFormat>=0.76:../../textproc/p5-Text-WikiFormat
DEPENDS+=	p5-Module-Refresh>=0.03:../../devel/p5-Module-Refresh
DEPENDS+=	p5-Encode>=2.13:../../textproc/p5-Encode

# Mailgate dependencies:
DEPENDS+=	p5-HTML-Tree>=3.18:../../www/p5-HTML-Tree
DEPENDS+=	p5-HTML-Format>=2.03:../../www/p5-HTML-Format
DEPENDS+=	p5-libwww>=5.76:../../www/p5-libwww
DEPENDS+=	p5-Term-ReadKey>=2.21:../../devel/p5-Term-ReadKey

# Dashboard dependencies:
DEPENDS+=	p5-MIME-Types-[0-9]*:../../mail/p5-MIME-Types
DEPENDS+=	p5-HTML-RewriteAttributes>=0.02:../../www/p5-HTML-RewriteAttributes

# ICAL dependencies:
DEPENDS+=	p5-Data-ICal-[0-9]*:../../time/p5-Data-ICal

# GPG dependencies:
DEPENDS+=	p5-PerlIO-eol-[0-9]*:../../devel/p5-PerlIO-eol
DEPENDS+=	p5-GnuPG-Interface-[0-9]*:../../security/p5-GnuPG-Interface

# Front-end dependencies:
.if !empty(PKG_OPTIONS:Mmodperl1)
DEPENDS+=	p5-libapreq>=1.2:../../www/p5-libapreq
DEPENDS+=	p5-Apache-DBI>=0.92:../../databases/p5-Apache-DBI
.elif !empty(PKG_OPTIONS:Mmodperl2)
DEPENDS+=	p5-Apache-DBI>=0.92:../../databases/p5-Apache-DBI
.elif !empty(PKG_OPTIONS:Mfastcgi)
DEPENDS+=	p5-FCGI>=0.67:../../www/p5-FCGI
DEPENDS+=	p5-CGI>=3.38:../../www/p5-CGI
.endif
PLIST_VARS+=	speedycgi
.if !empty(PKG_OPTIONS:Mspeedycgi)
DEPENDS+=	SpeedyCGI-[0-9]*:../../www/SpeedyCGI
PLIST.speedycgi=yes
.else
MAKE_FLAGS+=	RT_SPEEDYCGI_HANDLER=""

.PHONY: rm-speedycgi
post-install: rm-speedycgi
rm-speedycgi:
	rm -f ${DESTDIR}${PREFIX}/bin/mason_handler.scgi
.endif

# Back-end dependencies
.if !empty(PKG_OPTIONS:Mmysql)
DEPENDS+=	p5-DBD-mysql>=2.1018:../../databases/p5-DBD-mysql
_RT_DB_TYPE=	mysql
.elif !empty(PKG_OPTIONS:Mpgsql)
DEPENDS+=	p5-DBD-postgresql>=1.43:../../databases/p5-DBD-postgresql
_RT_DB_TYPE=	Pg
.elif !empty(PKG_OPTIONS:Moracle)
DEPENDS+=	p5-DBD-Oracle-[0-9]*:../../databases/p5-DBD-Oracle
_RT_DB_TYPE=	Oracle
.elif !empty(PKG_OPTIONS:Msqlite)
DEPENDS+=	p5-DBD-SQLite>=1.00:../../databases/p5-DBD-SQLite
_RT_DB_TYPE=	SQLite
.endif

# "Development" dependencies:
# XML::Simple is required by the installed script
# PREFIX/sbin/rt-dump-database
DEPENDS+=	p5-XML-Simple-[0-9]*:../../textproc/p5-XML-Simple

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
NO_BUILD=		yes
PKG_SYSCONFSUBDIR=	rt3

PKG_GROUPS=		${RT_GROUP}
PKG_GROUPS_VARS+=	RT_GROUP APACHE_GROUP
PKG_USERS_VARS+=	APACHE_USER

CONFIGURE_ARGS+=	--enable-layout=pkgsrc
CONFIGURE_ARGS+=	--with-rt-group=${RT_GROUP:Q}
CONFIGURE_ARGS+=	--with-db-type=${_RT_DB_TYPE:Q}
CONFIGURE_ARGS+=	--with-web-user=${APACHE_USER:Q}
CONFIGURE_ARGS+=	--with-web-group=${APACHE_GROUP:Q}
CONFIGURE_ARGS+=	--with-speedycgi=${PERL5_INSTALLVENDORBIN}/speedy
MESSAGE_SUBST+=		HOMEPAGE=${HOMEPAGE:Q}
MESSAGE_SUBST+=		RT_GROUP=${RT_GROUP:Q}
MESSAGE_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q}

post-extract:
	cd ${WRKSRC} && chmod -R g-w .

.include "Makefile.install"

.include "../../mk/bsd.pkg.mk"
