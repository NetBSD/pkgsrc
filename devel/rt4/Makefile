# $NetBSD: Makefile,v 1.45 2025/06/19 07:39:27 wiz Exp $

DISTNAME=	rt-4.4.8
PKGNAME=	${DISTNAME:S/rt/rt4/}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://download.bestpractical.com/pub/rt/release/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.bestpractical.com/rt/
COMMENT=	Industrial-grade ticketing system
LICENSE=	gnu-gpl-v2

# Dependency info. from sbin/rt-test-dependencies
# Core dependencies
DEPENDS+=	p5-Apache-Session>=1.53:../../www/p5-Apache-Session
DEPENDS+=	p5-Business-Hours>=0:../../time/p5-Business-Hours
DEPENDS+=	p5-CGI>=3.38:../../www/p5-CGI
DEPENDS+=	p5-CGI-Emulate-PSGI-[0-9]*:../../www/p5-CGI-Emulate-PSGI
DEPENDS+=	p5-CGI-PSGI-[0-9]*:../../www/p5-CGI-PSGI
DEPENDS+=	p5-Class-Accessor>=0.34:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Clone>=0:../../devel/p5-Clone
DEPENDS+=	p5-Convert-Color>=0:../../converters/p5-Convert-Color
DEPENDS+=	p5-Crypt-Eksblowfish-[0-9]*:../../security/p5-Crypt-Eksblowfish
DEPENDS+=	p5-CSS-Minifier-XS>=0:../../www/p5-CSS-Minifier-XS
DEPENDS+=	p5-CSS-Squish>=0.06:../../www/p5-CSS-Squish
DEPENDS+=	p5-Data-GUID-[0-9]*:../../devel/p5-Data-GUID
DEPENDS+=	p5-Data-ICal>=0:../../time/p5-Data-ICal
DEPENDS+=	p5-Data-Page-Pageset>=0:../../devel/p5-Data-Page-Pageset
DEPENDS+=	p5-Date-Extract>=0.07:../../time/p5-Date-Extract
DEPENDS+=	p5-Date-Manip-[0-9]*:../../devel/p5-Date-Manip
DEPENDS+=	p5-DateTime>=0.44:../../time/p5-DateTime
DEPENDS+=	p5-DateTime-Format-Natural>0.67:../../time/p5-DateTime-Format-Natural
DEPENDS+=	p5-DateTime-Locale>=0.40:../../time/p5-DateTime-Locale
DEPENDS+=	p5-DBI>=1.37:../../databases/p5-DBI
DEPENDS+=	p5-DBIx-SearchBuilder>=1.65:../../databases/p5-DBIx-SearchBuilder
DEPENDS+=	p5-Devel-GlobalDestruction-[0-9]*:../../devel/p5-Devel-GlobalDestruction
DEPENDS+=	p5-Devel-StackTrace>=1.19:../../devel/p5-Devel-StackTrace
DEPENDS+=	p5-Email-Address>=1.912:../../mail/p5-Email-Address
DEPENDS+=	p5-Email-Address-List>=0.06:../../mail/p5-Email-Address-List
DEPENDS+=	p5-File-ShareDir-[0-9]*:../../devel/p5-File-ShareDir
DEPENDS+=	p5-GraphViz2>=0:../../graphics/p5-GraphViz2
DEPENDS+=	p5-HTML-FormatText-WithLinks>=0.14:../../textproc/p5-HTML-FormatText-WithLinks
DEPENDS+=	p5-HTML-FormatText-WithLinks-AndTables-[0-9]*:../../textproc/p5-HTML-FormatText-WithLinks-AndTables
DEPENDS+=	p5-HTML-Mason>=1.43:../../www/p5-HTML-Mason
DEPENDS+=	p5-HTML-Mason-PSGIHandler>=0.52:../../www/p5-HTML-Mason-PSGIHandler
DEPENDS+=	p5-HTML-Quoted-[0-9]*:../../www/p5-HTML-Quoted
DEPENDS+=	p5-HTML-RewriteAttributes>=0.05:../../www/p5-HTML-RewriteAttributes
DEPENDS+=	p5-HTML-Scrubber>=0.08:../../www/p5-HTML-Scrubber
DEPENDS+=	p5-IPC-Run3-[0-9]*:../../devel/p5-IPC-Run3
DEPENDS+=	p5-JavaScript-Minifier-XS>=0:../../www/p5-JavaScript-Minifier-XS
DEPENDS+=	p5-JSON-[0-9]*:../../converters/p5-JSON
DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Locale-Maketext-Fuzzy-[0-9]*:../../misc/p5-Locale-Maketext-Fuzzy
DEPENDS+=	p5-Locale-Maketext-Lexicon>=0.32:../../misc/p5-Locale-Maketext-Lexicon
DEPENDS+=	p5-Log-Dispatch>=2.30:../../devel/p5-Log-Dispatch
DEPENDS+=	p5-MailTools>=1.57:../../mail/p5-MailTools
DEPENDS+=	p5-MIME-tools>=5.504:../../mail/p5-MIME-tools
DEPENDS+=	p5-Module-Refresh>=0.03:../../devel/p5-Module-Refresh
DEPENDS+=	p5-Module-Versions-Report>=1.05:../../devel/p5-Module-Versions-Report
DEPENDS+=	p5-Net-CIDR-[0-9]*:../../devel/p5-Net-CIDR
DEPENDS+=	p5-Net-IP-[0-9]*:../../net/p5-Net-IP
DEPENDS+=	p5-Parallel-ForkManager>=0:../../devel/p5-Parallel-ForkManager
DEPENDS+=	p5-Plack>=1.0002:../../www/p5-Plack
DEPENDS+=	p5-Pod-Parser>=0:../../textproc/p5-Pod-Parser
DEPENDS+=	p5-Starlet-[0-9]*:../../www/p5-Starlet
DEPENDS+=	p5-Regexp-Common-[0-9]*:../../textproc/p5-Regexp-Common
DEPENDS+=	p5-Regexp-Common-net-CIDR-[0-9]*:../../net/p5-Regexp-Common-net-CIDR
DEPENDS+=	p5-Regexp-IPv6-[0-9]*:../../net/p5-Regexp-IPv6
DEPENDS+=	p5-Role-Basic>=0.12:../../devel/p5-Role-Basic
DEPENDS+=	p5-Scalar-List-Utils-[0-9]*:../../devel/p5-Scalar-List-Utils
DEPENDS+=	p5-Scope-Upper>=0:../../devel/p5-Scope-Upper
DEPENDS+=	p5-Symbol-Global-Name>=0.04:../../devel/p5-Symbol-Global-Name
DEPENDS+=	p5-Text-Password-Pronounceable-[0-9]*:../../security/p5-Text-Password-Pronounceable
DEPENDS+=	p5-Text-Quoted>=2.07:../../textproc/p5-Text-Quoted
DEPENDS+=	p5-Text-Template>=1.44:../../textproc/p5-Text-Template
DEPENDS+=	p5-Text-WikiFormat>=0.76:../../textproc/p5-Text-WikiFormat
DEPENDS+=	p5-Text-Wrapper-[0-9]*:../../textproc/p5-Text-Wrapper
DEPENDS+=	p5-Time-modules-[0-9]*:../../time/p5-Time-modules
DEPENDS+=	p5-Tree-Simple>=1.04:../../devel/p5-Tree-Simple
DEPENDS+=	p5-UNIVERSAL-require-[0-9]*:../../devel/p5-UNIVERSAL-require
DEPENDS+=	p5-XML-RSS>=1.05:../../textproc/p5-XML-RSS
DEPENDS+=	p5-libwww>=0:../../www/p5-libwww

# Mailgate dependencies
# Net::SSL is a part of p5-Crypt-SSLeay.
DEPENDS+=	p5-Crypt-SSLeay-[0-9]*:../../security/p5-Crypt-SSLeay
DEPENDS+=	p5-LWP-Protocol-https-[0-9]*:../../www/p5-LWP-Protocol-https
DEPENDS+=	p5-Mozilla-CA-[0-9]*:../../security/p5-Mozilla-CA

# CLI dependencies
DEPENDS+=	p5-HTTP-Message-[0-9]*:../../www/p5-HTTP-Message
DEPENDS+=	p5-Term-ReadKey-[0-9]*:../../devel/p5-Term-ReadKey

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

# Graphviz dependencies
DEPENDS+=	p5-GraphViz-[0-9]*:../../graphics/p5-GraphViz

# GPG dependencies
DEPENDS+=	p5-File-Which-[0-9]*:../../devel/p5-File-Which
DEPENDS+=	p5-GnuPG-Interface-[0-9]*:../../security/p5-GnuPG-Interface
DEPENDS+=	p5-PerlIO-eol-[0-9]*:../../devel/p5-PerlIO-eol

# SMIME dependencies
DEPENDS+=	p5-String-ShellQuote-[0-9]*:../../textproc/p5-String-ShellQuote
DEPENDS+=	p5-Crypt-X509-[0-9]*:../../security/p5-Crypt-X509
# File::Which is in GPG dependencies.

# USERLOGO dependency
# Module::Pluggable will be removed from the Perl core distribution...
DEPENDS+=	p5-Module-Pluggable-[0-9]*:../../devel/p5-Module-Pluggable
DEPENDS+=	p5-Convert-Color-[0-9]*:../../converters/p5-Convert-Color

DEPENDS+=	p5-Text-Reform-[0-9]*:../../textproc/p5-Text-Reform

DEPENDS+=	p5-Sub-HandlesVia-[0-9]*:../../devel/p5-Sub-HandlesVia


.include "dirs.mk"
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
SUBST_VARS.prefix+=	RT_VAR_DIR RT_LOCAL_DIR

SUBST_CLASSES+=		etcpath
SUBST_MESSAGE.etcpath=	Setting non-sysconfdir etcpath
SUBST_FILES.etcpath=	sbin/rt-setup-database.in
SUBST_FILES.etcpath+=	share/html/Install/Initialize.html
SUBST_FILES.etcpath+=	lib/RT/Handle.pm
SUBST_SED.etcpath=	-e 's,\$$RT::EtcPath,"${PREFIX}/share/rt4/etc",'
SUBST_STAGE.etcpath=	pre-configure

SUBST_CLASSES+=		egpath
SUBST_FILES.egpath=	Makefile.in
SUBST_SED.egpath=	-e 's,@CONFIG_FILE_PATH_R@,${RT_EXAMPLE_DIR},'
SUBST_SED.egpath+=	-e 's,@RT_ETC_PATH_R@,${RT4DIR}/etc,'
SUBST_STAGE.egpath=	pre-configure

GNU_CONFIGURE=		yes
NO_BUILD=		yes
USE_LANGUAGES=		c
USE_TOOLS+=		perl:run
PKG_SYSCONFSUBDIR=	rt4

USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS+=	--enable-layout=pkgsrc
CONFIGURE_ARGS+=	--with-db-type=${RT_DB_TYPE}

RT_CONFIG_FILES=	RT_Config.pm RT_SiteConfig.pm

.for _file_ in ${RT_CONFIG_FILES}
CONF_FILES_PERMS+=	${RT_EXAMPLE_DIR}/${_file_} \
			${PKG_SYSCONFDIR}/${_file_} \
			${APACHE_USER} ${APACHE_GROUP} \
			444
.endfor

OWN_DIRS+=		${RT_VAR_DIR} ${RT_LOCAL_DIR} ${RT_LOCAL_DIR}/etc
OWN_DIRS+=		${RT_LOCAL_DIR}/lib ${RT_LOCAL_DIR}/po ${RT_LOCAL_DIR}/plugins
OWN_DIRS+=		${RT_LOCAL_DIR}/html ${RT_LOCAL_DIR}/static

OWN_DIRS_PERMS+=	${RT_VAR_DIR}/mason_data	${APACHE_USER}	${APACHE_GROUP}	0770
OWN_DIRS_PERMS+=	${RT_VAR_DIR}/mason_data/cache	${APACHE_USER}	${APACHE_GROUP}	0770
OWN_DIRS_PERMS+=	${RT_VAR_DIR}/mason_data/etc	${APACHE_USER}	${APACHE_GROUP}	0770
OWN_DIRS_PERMS+=	${RT_VAR_DIR}/mason_data/obj	${APACHE_USER}	${APACHE_GROUP}	0770
OWN_DIRS_PERMS+=	${RT_VAR_DIR}/session_data	${APACHE_USER}	${APACHE_GROUP}	0770

REPLACE_PERL+=		etc/upgrade/upgrade-mysql-schema.pl

INSTALL_MAKE_FLAGS+=	BIN_OWNER=${ROOT_USER:Q} LIBS_OWNER=${ROOT_USER:Q} \
			LIBS_GROUP=${ROOT_GROUP:Q} RTGROUP=${ROOT_GROUP:Q} \
			WEB_USER=${ROOT_USER:Q} WEB_GROUP=${ROOT_GROUP:Q}

.include "../../mk/bsd.pkg.mk"
