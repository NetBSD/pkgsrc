# $NetBSD: Makefile,v 1.81 2012/10/03 11:24:42 asau Exp $

DISTNAME=	mgetty1.1.37-Jun05
PKGNAME=	mgetty-1.1.37
PKGREVISION=	2
CATEGORIES=	comms
MASTER_SITES=	ftp://alpha.greenie.net/pub/mgetty/source/1.1/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mgetty.greenie.net/
COMMENT=	Handle external logins, send and receive faxes
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=		no

BUILD_DEPENDS+=	texi2roff-[0-9]*:../../textproc/texi2roff

CONFLICTS=	hylafax-[0-9]*

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

MAKE_ENV+=		MGETTY_CONFDIR=${PKG_SYSCONFDIR:Q} PERL5=${PERL5:Q}
MAKE_ENV+=		ROOT_USER=${REAL_ROOT_USER:Q}
MAKE_ENV+=		ROOT_GROUP=${REAL_ROOT_GROUP:Q}
MAKE_FLAGS+=		prefix=${DESTDIR:Q}${PREFIX:Q}                  \
			spool=${VARBASE}/spool				\
			INFODIR=${DESTDIR:Q}${PREFIX:Q}/${PKGINFODIR:Q} \
			MAN1DIR=${DESTDIR:Q}${PREFIX:Q}/${PKGMANDIR:Q}/man1\
			MAN4DIR=${DESTDIR:Q}${PREFIX:Q}/${PKGMANDIR:Q}/man4\
			MAN5DIR=${DESTDIR:Q}${PREFIX:Q}/${PKGMANDIR:Q}/man5\
			MAN8DIR=${DESTDIR:Q}${PREFIX:Q}/${PKGMANDIR:Q}/man8\
			LIBS=${LIBS:Q}

INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} CONFDIR=${DESTDIR:Q}${EXAMPLES_DIR:Q}
BUILD_MAKE_FLAGS=	${MAKE_FLAGS:S,${DESTDIR},,} CONFDIR=${PKG_SYSCONFDIR:Q}

CFLAGS.SunOS+=		-Dsolaris2
CFLAGS+=		-DDEVICE_GROUP=\"${REAL_ROOT_GROUP}\"

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "SunOS"
LIBS+=			-lutil
.endif

USE_TOOLS+=		makeinfo perl:run

INFO_FILES=		yes
PKG_SYSCONFSUBDIR=	mgetty+sendfax

PKG_GROUPS=		dialer
PKG_USERS=		fax:dialer
#USERGROUP_PHASE=	pre-install

EXAMPLES_DIR=		${PREFIX}/share/examples/mgetty+sendfax
SPOOL_DIR=		${VARBASE}/spool/fax

.for cfg in		dialin.config		\
			faxheader		\
			faxrunq.config		\
			faxspool.rules.sample	\
			login.config		\
			mgetty.config		\
			voice.conf

CONF_FILES+=		${EXAMPLES_DIR}/${cfg} ${PKG_SYSCONFDIR}/${cfg}
.endfor

ROOT_DIR_PERMS=		${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 755
FAX_DIR_PERMS=		fax ${REAL_ROOT_GROUP} 755
SETUID_FAX_PERMS=	fax ${REAL_ROOT_GROUP} 4711

# XXX the package's makefile sets SPOOL_DIR to FAX_DIR_PERMS but the
# pkgsrc package has had it as ROOT_DIR_PERMS. I'm going to leave it
# the way pkgsrc had it; if you find it breaks that way please file a PR.
OWN_DIRS_PERMS+=	${SPOOL_DIR} ${ROOT_DIR_PERMS}
OWN_DIRS_PERMS+=	${SPOOL_DIR}/incoming ${ROOT_DIR_PERMS}
OWN_DIRS_PERMS+=	${SPOOL_DIR}/outgoing ${FAX_DIR_PERMS}

SPECIAL_PERMS+=		lib/mgetty+sendfax/faxq-helper ${SETUID_FAX_PERMS}

SUBST_CLASSES+=		prefix
SUBST_FILES.prefix=	faxrunq.config
SUBST_SED.prefix=	-e 's|/usr/local|${PREFIX}|'
SUBST_SED.prefix+=	-e 's|/var/log|${VARBASE}/log|'
SUBST_STAGE.prefix=	pre-configure
SUBST_MESSAGE.prefix=	Fixing hardcoded installation prefix.

.include "../../graphics/netpbm/buildlink3.mk"

post-extract:
	cd ${WRKSRC} && cp policy.h-dist policy.h

do-configure:
	mv ${WRKSRC}/doc/fax.1in ${WRKSRC}/doc/sendfax.1in

.include "../../mk/bsd.pkg.mk"
