# $NetBSD: Makefile,v 1.1.1.1 2004/08/03 15:33:49 cube Exp $

DISTNAME=		rt-3.2.1
CATEGORIES=		devel
MASTER_SITES=		http://download.bestpractical.com/pub/rt/release/

MAINTAINER=		cube@NetBSD.org
HOMEPAGE=		http://bestpractical.com/rt/
COMMENT=		Industrial-grade ticketing system

.include "Makefile.options"

# Core dependencies:
DEPENDS+=	p5-Digest-[0-9]*:../../security/p5-Digest
DEPENDS+=	p5-Digest-MD5>=2.27:../../security/p5-Digest-MD5
DEPENDS+=	p5-DBI>=1.37:../../databases/p5-DBI
DEPENDS+=	p5-Test-Inline>=0.15:../../devel/p5-Test-Inline
DEPENDS+=	p5-Class-ReturnValue>=0.40:../../devel/p5-Class-ReturnValue
DEPENDS+=	p5-DBIx-SearchBuilder>=1.01:../../databases/p5-DBIx-SearchBuilder
DEPENDS+=	p5-Text-Template>=1.43:../../textproc/p5-Text-Template
DEPENDS+=	p5-HTML-Parser>=3.35:../../www/p5-HTML-Parser
DEPENDS+=	p5-HTML-Scrubber>=0.08:../../www/p5-HTML-Scrubber
DEPENDS+=	p5-Net>=1.15:../../net/p5-Net
DEPENDS+=	p5-Log-Dispatch>=2.0:../../devel/p5-Log-Dispatch
DEPENDS+=	p5-Locale-Maketext-Lexicon>=0.32:../../misc/p5-Locale-Maketext-Lexicon
DEPENDS+=	p5-Locale-Maketext-Fuzzy>=0.02:../../misc/p5-Locale-Maketext-Fuzzy
DEPENDS+=	p5-MIME-tools>=5.411.1:../../mail/p5-MIME-tools
DEPENDS+=	p5-MailTools>=1.57:../../mail/p5-MailTools
DEPENDS+=	p5-Text-Wrapper>=1.0:../../textproc/p5-Text-Wrapper
DEPENDS+=	p5-Time>=101.062101:../../time/p5-Time
DEPENDS+=	p5-Term-ReadKey>=2.21:../../devel/p5-Term-ReadKey
DEPENDS+=	p5-Text-Autoformat>=1.04:../../textproc/p5-Text-Autoformat
DEPENDS+=	p5-Text-Quoted>=1.5:../../textproc/p5-Text-Quoted
DEPENDS+=	p5-Tree-Simple>=1.04:../../devel/p5-Tree-Simple
DEPENDS+=	p5-Module-Versions-Report-[0-9]*:../../devel/p5-Module-Versions-Report

# Mason dependencies:
DEPENDS+=	p5-Params-Validate>=0.02:../../devel/p5-Params-Validate
DEPENDS+=	p5-Cache-Cache>=1.02:../../devel/p5-Cache-Cache
DEPENDS+=	p5-Exception-Class>=1.14:../../devel/p5-Exception-Class
DEPENDS+=	p5-HTML-Mason>=1.23:../../www/p5-HTML-Mason
DEPENDS+=	p5-MLDBM>=2.01:../../databases/p5-MLDBM
DEPENDS+=	p5-FreezeThaw>=0.43:../../devel/p5-FreezeThaw
DEPENDS+=	p5-Storable>=2.08:../../devel/p5-Storable
DEPENDS+=	p5-Apache-Session>=1.53:../../www/p5-Apache-Session
DEPENDS+=	p5-XML-RSS-[0-9]*:../../textproc/p5-XML-RSS

# Mailgate dependencies:
DEPENDS+=	p5-HTML-Tree>=3.18:../../www/p5-HTML-Tree
DEPENDS+=	p5-HTML-Format>=2.03:../../www/p5-HTML-Format
DEPENDS+=	p5-libwww>=5.76:../../www/p5-libwww

# Front-end dependencies:
.if !empty(PKG_OPTIONS:Mfrontend-modperl1)
DEPENDS+=	p5-libapreq>=1.2:../../www/p5-libapreq
DEPENDS+=	p5-Apache-DBI>=0.92:../../databases/p5-Apache-DBI
.elif !empty(PKG_OPTIONS:Mfrontend-modperl2)
DEPENDS+=	p5-Apache-DBI>=0.92:../../databases/p5-Apache-DBI
.elif !empty(PKG_OPTIONS:Mfrontend-fastcgi)
DEPENDS+=	p5-FCGI>=0.67:../../www/p5-FCGI
.endif

# Back-end dependencies
.if !empty(PKG_OPTIONS:Mbackend-mysql)
DEPENDS+=	mysql-client>=4.0.9:../../databases/mysql4-client
DEPENDS+=	p5-DBD-mysql>=2.1018:../../databases/p5-DBD-mysql
_RT_DB_TYPE=		mysql
.elif !empty(PKG_OPTIONS:Mbackend-pgsql)
DEPENDS+=	p5-DBD-Pg-[0-9]*:../../database/p5-DBD-Pg
_RT_DB_TYPE=		Pg
.endif

# Dev dependencies:
DEPENDS+=	p5-Regexp-Common>=2.113:../../textproc/p5-Regexp-Common
DEPENDS+=	p5-Apache-Test-[0-9]*:../../wip/p5-Apache-Test
DEPENDS+=	p5-WWW-Mechanize>=0.72:../../www/p5-WWW-Mechanize

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
NO_BUILD=		yes
USE_PKGINSTALL=		yes
PKG_SYSCONFSUBDIR=	rt3

PERL5_REQD+=		5.8.3

PKG_GROUPS=		${RT_GROUP}

CONFIGURE_ARGS+=	--enable-layout=pkgsrc
CONFIGURE_ARGS+=	--with-rt-group=${RT_GROUP}
CONFIGURE_ARGS+=	--with-db-type=${_RT_DB_TYPE}
CONFIGURE_ARGS+=	--with-web-user=${APACHE_USER}
CONFIGURE_ARGS+=	--with-web-group=${APACHE_GROUP}

MESSAGE_SUBST+=		HOMEPAGE=${HOMEPAGE}
MESSAGE_SUBST+=		RT_GROUP=${RT_GROUP}
MESSAGE_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

.include "Makefile.install"

.include "../../mk/bsd.pkg.mk"
