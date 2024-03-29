# $NetBSD: Makefile,v 1.81 2023/10/24 22:09:50 wiz Exp $

VERSION=	6.2.56
DISTNAME=	sympa-${VERSION}
PKGREVISION=	5
CATEGORIES=	mail
MASTER_SITES=	https://github.com/sympa-community/sympa/releases/download/${VERSION}/

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	https://www.sympa.org/
COMMENT=	Mailing list manager
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	destdir

DEPENDS+=		mhonarc-[0-9]*:../../mail/mhonarc
DEPENDS+=		p5-Archive-Zip>=1.05:../../archivers/p5-Archive-Zip
DEPENDS+=		p5-AuthCAS>=1.5:../../security/p5-AuthCAS
DEPENDS+=		p5-CGI>=2.52:../../www/p5-CGI
DEPENDS+=		p5-CGI-Fast>=2.10:../../www/p5-CGI-Fast
DEPENDS+=		p5-Crypt-CipherSaber>=0.50:../../security/p5-Crypt-CipherSaber
DEPENDS+=		p5-DBD-Sybase>=0.90:../../databases/p5-DBD-Sybase
DEPENDS+=		p5-DBI>=1.06:../../databases/p5-DBI
#DEPENDS+=		{perl>=5.10,p5-Digest-MD5>=2.00}:../../security/p5-Digest-MD5
DEPENDS+=		p5-Email-Date-Format>=1.002:../../mail/p5-Email-Date-Format
DEPENDS+=		p5-FCGI>=0.67:../../www/p5-FCGI
DEPENDS+=		p5-File-Copy-Recursive>=0.38:../../sysutils/p5-File-Copy-Recursive
DEPENDS+=		p5-HTML-Format>=2.10:../../www/p5-HTML-Format
DEPENDS+=		p5-HTML-StripScripts-Parser>=1.02:../../www/p5-HTML-StripScripts-Parser
DEPENDS+=		p5-HTML-Tree>=4.2:../../www/p5-HTML-Tree
DEPENDS+=		p5-IO-Socket-SSL>=0.90:../../security/p5-IO-Socket-SSL
DEPENDS+=		p5-IO-stringy>=1.0:../../devel/p5-IO-stringy
DEPENDS+=		p5-Locale-libintl>=1.16:../../misc/p5-Locale-libintl
#DEPENDS+=		{perl>=5.7.3,p5-MIME-Base64>=1.0}:../../converters/p5-MIME-Base64
DEPENDS+=		p5-MIME-EncWords>=1.014.000:../../mail/p5-MIME-EncWords
DEPENDS+=		p5-MIME-Lite-HTML>=1.23:../../mail/p5-MIME-Lite-HTML
DEPENDS+=		p5-MIME-tools>=5.209:../../mail/p5-MIME-tools
DEPENDS+=		p5-MailTools>=1.51:../../mail/p5-MailTools
#DEPENDS+=		{perl>=5.10,p5-Net>=1.0}:../../net/p5-Net
DEPENDS+=		p5-Net-Netmask>=1.9015:../../devel/p5-Net-Netmask
DEPENDS+=		p5-Net-SSLeay>=1.16:../../security/p5-Net-SSLeay
DEPENDS+=		p5-Regexp-Common>=2.120:../../textproc/p5-Regexp-Common
DEPENDS+=		p5-SOAP-Lite-[0-9]*:../../net/p5-SOAP-Lite
DEPENDS+=		p5-Template-Toolkit>=2.20:../../www/p5-Template-Toolkit
DEPENDS+=		p5-Term-ProgressBar>=2.09:../../devel/p5-Term-ProgressBar
#DEPENDS+=		{perl>=5.15.1,p5-Time-HiRes>=1.9724}:../../time/p5-Time-HiRes
DEPENDS+=		p5-Unicode-LineBreak>=2012.02:../../textproc/p5-Unicode-LineBreak
DEPENDS+=		p5-XML-LibXML>=1.61:../../textproc/p5-XML-LibXML
DEPENDS+=		p5-libwww>=1.09:../../www/p5-libwww
DEPENDS+=		p5-perl-ldap>=0.27:../../databases/p5-perl-ldap
DEPENDS+=		p5-DateTime>=1.2000:../../time/p5-DateTime
DEPENDS+=		p5-DateTime-Format-Mail>=0.401:../../time/p5-DateTime-Format-Mail
DEPENDS+=		p5-Email-Simple>=2.208:../../mail/p5-Email-Simple
DEPENDS+=		p5-File-NFSLock>=1.27:../../devel/p5-File-NFSLock
DEPENDS+=		p5-Net-CIDR>=0.18:../../devel/p5-Net-CIDR
DEPENDS+=		p5-Net-DNS>=1.01:../../net/p5-Net-DNS
DEPENDS+=		p5-Proc-ProcessTable>=0.53:../../devel/p5-Proc-ProcessTable
#DEPENDS.SunOS+=	{perl>=5.10,p5-DB_File>=1.75}:../../databases/p5-DB_File

OPSYSVARS+=	DEPENDS

USE_TOOLS+=		gmake msgfmt perl:run

GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--bindir=${PREFIX}/sympa/bin
CONFIGURE_ARGS+=	--with-cgidir=${PREFIX}/sympa/libexec/cgi-bin
CONFIGURE_ARGS+=	--libexecdir=${PREFIX}/sympa/bin
CONFIGURE_ARGS+=	--localedir=${PREFIX}/share/locale
CONFIGURE_ARGS+=	--sbindir=${PREFIX}/sympa/bin
CONFIGURE_ARGS+=	--with-defaultdir=${PREFIX}/sympa/default
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-confdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-expldir=${SYMPA_VARBASE}/list_data
CONFIGURE_ARGS+=	--with-lockdir=${SYMPA_VARBASE}/lock
CONFIGURE_ARGS+=	--with-modulesdir=${PREFIX}/sympa/bin
CONFIGURE_ARGS+=	--with-piddir=${SYMPA_VARBASE}/run
CONFIGURE_ARGS+=	--with-scriptdir=${PREFIX}/sympa/bin
CONFIGURE_ARGS+=	--with-spooldir=${SYMPA_SPOOL:Q}
CONFIGURE_ARGS+=	--mandir=${MAN8PREFIX}/man
CONFIGURE_ARGS+=	--with-perl=${PERL5:Q}
CONFIGURE_ARGS+=	--sharedstatedir=${SYMPA_PREFIX}/libdata
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share
CONFIGURE_ARGS+=	--localstatedir=${SYMPA_VARBASE}
CONFIGURE_ARGS+=	--docdir=${PREFIX}/share/doc/sympa
CONFIGURE_ARGS+=	--with-user=${SYMPA_USER:Q}
CONFIGURE_ARGS+=	--with-group=${SYMPA_GROUP:Q}

PKG_SYSCONFSUBDIR?=	sympa

PKG_OPTIONS_VAR=	PKG_OPTIONS.sympa
PKG_SUPPORTED_OPTIONS=	mysql pgsql

RCD_SCRIPTS=		archived bounced bulk sympa task_manager

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmysql)
DEPENDS+=	p5-DBD-mysql>=2.0407:../../databases/p5-DBD-mysql
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
DEPENDS+=	p5-DBD-postgresql>=0.90:../../databases/p5-DBD-postgresql
.endif

SYMPA_USER?=	sympa
SYMPA_GROUP?=	sympa
SYMPA_VARBASE?=	/var/sympa

SYMPA_PREFIX=	${PREFIX}/sympa
SYMPA_SPOOL=	${SYMPA_VARBASE}/spool
SYMPA_BIN=	${SYMPA_PREFIX}/bin

PKG_GROUPS=	${SYMPA_GROUP}
PKG_USERS=	${SYMPA_USER}:${SYMPA_GROUP}

PKG_HOME.${SYMPA_USER}=		${SYMPA_VARBASE}

PKG_GROUPS_VARS+=	SYMPA_GROUP
PKG_USERS_VARS+=	SYMPA_USER
BUILD_DEFS+=		SYMPA_VARBASE

OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR} ${SYMPA_USER} ${SYMPA_GROUP} 755
.for d in create_list_templates general_task_models \
	scenari task_models templates wws_templates
OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR}/${d} ${SYMPA_USER} ${SYMPA_GROUP} 755
.endfor
OWN_DIRS_PERMS+=	${SYMPA_VARBASE} ${SYMPA_USER} ${SYMPA_GROUP} 775
OWN_DIRS_PERMS+=	${SYMPA_VARBASE}/expl ${SYMPA_USER} ${SYMPA_GROUP} 770
OWN_DIRS_PERMS+=	${SYMPA_VARBASE}/lock ${SYMPA_USER} ${SYMPA_GROUP} 770
OWN_DIRS_PERMS+=	${SYMPA_VARBASE}/run ${SYMPA_USER} ${SYMPA_GROUP} 770
OWN_DIRS_PERMS+=	${SYMPA_VARBASE}/arc ${SYMPA_USER} ${SYMPA_GROUP} 770
OWN_DIRS_PERMS+=	${SYMPA_VARBASE}/bounce ${SYMPA_USER} ${SYMPA_GROUP} 770
OWN_DIRS_PERMS+=	${SYMPA_VARBASE}/list_data ${SYMPA_USER} ${SYMPA_GROUP} 775
OWN_DIRS_PERMS+=	${SYMPA_VARBASE}/list_data/static_content ${SYMPA_USER} ${SYMPA_GROUP} 775
OWN_DIRS_PERMS+=	${SYMPA_VARBASE}/list_data/static_content/icons ${SYMPA_USER} ${SYMPA_GROUP} 775
OWN_DIRS_PERMS+=	${SYMPA_SPOOL} ${SYMPA_USER} ${SYMPA_GROUP} 770
OWN_DIRS_PERMS+=	${SYMPA_SPOOL}/msg ${SYMPA_USER} ${SYMPA_GROUP} 770
OWN_DIRS_PERMS+=	${SYMPA_SPOOL}/digest ${SYMPA_USER} ${SYMPA_GROUP} 770
OWN_DIRS_PERMS+=	${SYMPA_SPOOL}/moderation ${SYMPA_USER} ${SYMPA_GROUP} 770
OWN_DIRS_PERMS+=	${SYMPA_SPOOL}/expire ${SYMPA_USER} ${SYMPA_GROUP} 770
OWN_DIRS_PERMS+=	${SYMPA_SPOOL}/auth ${SYMPA_USER} ${SYMPA_GROUP} 770
OWN_DIRS_PERMS+=	${SYMPA_SPOOL}/outgoing ${SYMPA_USER} ${SYMPA_GROUP} 770
OWN_DIRS_PERMS+=	${SYMPA_SPOOL}/task ${SYMPA_USER} ${SYMPA_GROUP} 770
OWN_DIRS_PERMS+=	${SYMPA_SPOOL}/tmp ${SYMPA_USER} ${SYMPA_GROUP} 770

SPECIAL_PERMS+=	${SYMPA_BIN}/sympa_newaliases-wrapper ${REAL_ROOT_USER} ${SYMPA_GROUP} 4550
SPECIAL_PERMS+=	${SYMPA_BIN}/bouncequeue ${SYMPA_USER} ${SYMPA_GROUP} 4555
SPECIAL_PERMS+=	${SYMPA_BIN}/familyqueue ${SYMPA_USER} ${SYMPA_GROUP} 4555
SPECIAL_PERMS+=	${SYMPA_BIN}/queue ${SYMPA_USER} ${SYMPA_GROUP} 4555
SPECIAL_PERMS+=	${SYMPA_PREFIX}/libexec/cgi-bin/wwsympa-wrapper.fcgi \
			 ${SYMPA_USER} ${SYMPA_GROUP} 6555
SPECIAL_PERMS+=	${SYMPA_PREFIX}/libexec/cgi-bin/sympa_soap_server-wrapper.fcgi \
			 ${SYMPA_USER} ${SYMPA_GROUP} 6555

CONF_FILES=	${PREFIX}/share/examples/sympa/sympa.conf \
		${PKG_SYSCONFDIR}/sympa.conf
.for f in favicon_sympa.png logo_sympa.png
CONF_FILES+=	${PREFIX}/sympa/static_content/icons/${f} \
		${SYMPA_VARBASE}/list_data/static_content/icons/${f}
.endfor

MESSAGE_SUBST+=	SYMPA_BIN=${SYMPA_BIN} SYMPA_VARBASE=${SYMPA_VARBASE}

INSTALLATION_DIRS+=	share/doc/sympa

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	configure
SUBST_SED.paths=	-e "s|localstatedir/lib/sympa|localstatedir|g"
SUBST_SED.paths+=	-e "s|prefix/static_content|prefix/sympa/static_content|g"
SUBST_SED.paths+=	-e "s|prefix/default|prefix/sympa/default|g"
SUBST_SED.paths+=	-e "s|prefix/arc|localstatedir/arc|g"
SUBST_SED.paths+=	-e "s|prefix/bounce|localstatedir/bounce|g"
SUBST_MESSAGE.paths=	Fixing configure paths

post-install:
	${INSTALL_DATA} ${WRKSRC}/NEWS.md ${DESTDIR}${PREFIX}/share/doc/sympa/NEWS.md
	${CHOWN} -R ${ROOT_USER}:${ROOT_GROUP} ${DESTDIR}${SYMPA_PREFIX}/static_content
	${CHMOD} a-w \
	    ${DESTDIR}${SYMPA_PREFIX}/libexec/cgi-bin/wwsympa-wrapper.fcgi \
	    ${DESTDIR}${SYMPA_PREFIX}/libexec/cgi-bin/sympa_soap_server-wrapper.fcgi \
	    ${DESTDIR}${SYMPA_BIN}/bouncequeue \
	    ${DESTDIR}${SYMPA_BIN}/familyqueue \
	    ${DESTDIR}${SYMPA_BIN}/queue

.include "../../lang/perl5/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
