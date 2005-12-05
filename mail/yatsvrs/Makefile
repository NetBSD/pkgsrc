# $NetBSD: Makefile,v 1.14 2005/12/05 23:55:12 rillig Exp $
#

DISTNAME=		yatsvrs-5.00p6
PKGNAME=		${DISTNAME:S/p/./}
PKGREVISION=		4
CATEGORIES=		mail
MASTER_SITES=		ftp://ftp.jone-system.com/pub/jepro/yatsvr/

MAINTAINER=		taca@NetBSD.org
HOMEPAGE=		# not available
COMMENT=		Extended POP3 server and some supporting servers

CONFLICTS=		ascyd-* yatsvr4-*

USE_PKGINSTALL=		yes
GNU_CONFIGURE=		yes
DOCS=			IMPORTANT README UPDATE doc/YATCONF doc/YATEXT4
DOCDIR=			${PREFIX}/share/doc/yatsvr5
EXAMPLES=		yatrc2 yatsvrrc
EXAMPLESDIR=		${PREFIX}/share/examples/yatsvr5

CONFIGURE_ARGS+=	--enable-popper-xmit
CONFIGURE_ARGS+=	--with-log-facility=${YATSVR_LOGFAC:Q}
CONFIGURE_ARGS+=	--with-yat-sys-dir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-yat-sys-old-dir-v4=${OLDCONFDIR:Q}
CONFIGURE_ARGS+=	--enable-shadow-password

DEINSTALL_FILE=		${WRKDIR}/DEINSTALL
INSTALL_FILE=		${WRKDIR}/INSTALL

FILES_SUBST+=		DEFAULT_ADMIN=${DEFAULT_YATADMIN:Q}
FILES_SUBST+=		YATSVR_MINGID=${YATSVR_MINGID:Q}
FILES_SUBST+=		YATSVR_MAXGID=${YATSVR_MAXGID:Q}

DEINSTALL_EXTRA_TMPL=	${.CURDIR}/DEINSTALL
INSTALL_EXTRA_TMPL=	${.CURDIR}/INSTALL

.for f in ${EXAMPLES}
CONF_FILES+=		${EXAMPLESDIR}/${f}	${PKG_SYSCONFDIR}/${f}
.endfor
OWN_DIRS+=		${PKG_SYSCONFDIR}

.include "../../mk/bsd.prefs.mk"

YATSVR_LOGFAC?=		LOG_LOCAL4
YATSVR_MINGID?=		1001
YATSVR_MAXGID?=		64999
DEFAULT_YATADMIN?=	root
PKG_SYSCONFSUBDIR?=	yatsvr5
OLDCONFDIR?=		${PKG_SYSCONFBASE}/yat

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCDIR}
.endfor
	${INSTALL_DATA_DIR} ${EXAMPLESDIR}
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/sample/${f} ${EXAMPLESDIR}/${f}
.endfor

.include "../../mk/bsd.pkg.mk"
