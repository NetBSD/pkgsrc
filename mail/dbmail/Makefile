# $NetBSD: Makefile,v 1.91 2026/03/03 20:07:00 tnn Exp $

DISTNAME=	dbmail-3.5.5
PKGREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=dbmail/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dbmail/dbmail
COMMENT=	Store and retrieve mail messages in a database
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=		asciidoc-[0-9]*:../../textproc/asciidoc
TOOL_DEPENDS+=		xmlto-[0-9]*:../../textproc/xmlto

USE_TOOLS+=		gmake pkg-config pax perl
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-logdir=${VARBASE}/log
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}/run
CONFIGURE_ARGS+=	--with-zdb=${BUILDLINK_PREFIX.libzdb}
CONFIGURE_ARGS+=	--enable-manpages
REPLACE_PERL+=		man/fixsp.pl

BUILD_DEFS+=		VARBASE DBMAIL_USER DBMAIL_GROUP

EGDIR=			${PREFIX}/share/examples/dbmail
CONF_FILES_PERMS+=	${EGDIR}/dbmail.conf ${PKG_SYSCONFDIR}/dbmail.conf \
			  ${DBMAIL_USER} ${DBMAIL_GROUP} 0640
OWN_DIRS_PERMS+=	${VARBASE}/log/dbmail ${DBMAIL_USER} ${DBMAIL_GROUP} 0750
RCD_SCRIPTS=		dbmail dbmailhttpd dbmailimapd dbmaillmtpd dbmailpop3d
DATADIR=		${PREFIX}/share/dbmail

DBMAIL_USER?=		dbmail
DBMAIL_GROUP?=		dbmail
PKG_USERS_VARS=		DBMAIL_USER
PKG_GROUPS_VARS=	DBMAIL_GROUP
PKG_GROUPS=		${DBMAIL_GROUP}
PKG_USERS=		${DBMAIL_USER}:${DBMAIL_GROUP}
FILES_SUBST+=		DBMAIL_USER=${DBMAIL_USER}
FILES_SUBST+=		DBMAIL_GROUP=${DBMAIL_GROUP}

SUBST_CLASSES+=		fix-cfg
SUBST_STAGE.fix-cfg=	pre-configure
SUBST_MESSAGE.fix-cfg=	Substituting configurtion defaults.
SUBST_FILES.fix-cfg=	dbmail.conf
SUBST_SED.fix-cfg=	-e 's,nobody$$,${DBMAIL_USER},g'
SUBST_SED.fix-cfg+=	-e 's,nogroup$$,${DBMAIL_GROUP},g'
SUBST_SED.fix-cfg+=	-e 's,/var/run/dbmail$$,${VARBASE}/run/dbmail,g'
SUBST_SED.fix-cfg+=	-e 's,/var/log/dbmail/dbmail.log$$,${VARBASE}/log/dbmail/dbmail.log,g'

INSTALLATION_DIRS=	lib ${PKGMANDIR}/man1 ${PKGMANDIR}/man5 ${PKGMANDIR}/man8 sbin ${EGDIR} ${DATADIR}/sql

post-install:
	${INSTALL_DATA} ${WRKSRC}/dbmail.conf ${DESTDIR}${EGDIR}
.for f in mysql postgresql sqlite
	cd ${WRKSRC}/sql && pax -rw ${f} ${DESTDIR}${DATADIR}/sql/.
.endfor

.include "options.mk"

.include "../../databases/libzdb/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.8.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../mail/gmime3/buildlink3.mk"
.include "../../security/mhash/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
