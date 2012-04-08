# $NetBSD: Makefile,v 1.77.2.1 2012/04/08 11:07:19 sbd Exp $

DISTNAME=	mgetty1.1.37-Jun05
PKGNAME=	mgetty-1.1.37
PKGREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	ftp://alpha.greenie.net/pub/mgetty/source/1.1/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mgetty.greenie.net/
COMMENT=	Handle external logins, send and receive faxes
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=		no

BUILD_DEPENDS+=	texi2roff-[0-9]*:../../textproc/texi2roff

CONFLICTS=	hylafax-[0-9]*

PKG_DESTDIR_SUPPORT=	destdir

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

MAKE_ENV+=		MGETTY_CONFDIR=${PKG_SYSCONFDIR:Q} PERL5=${PERL5:Q}
MAKE_ENV+=		ROOT_USER=${ROOT_USER:Q} ROOT_GROUP=${ROOT_GROUP}
MAKE_FLAGS+=		prefix=${DESTDIR:Q}${PREFIX:Q}                  \
			INFODIR=${DESTDIR:Q}${PREFIX:Q}/${PKGINFODIR:Q} \
			MAN1DIR=${DESTDIR:Q}${PREFIX:Q}/${PKGMANDIR:Q}/man1\
			MAN4DIR=${DESTDIR:Q}${PREFIX:Q}/${PKGMANDIR:Q}/man4\
			MAN5DIR=${DESTDIR:Q}${PREFIX:Q}/${PKGMANDIR:Q}/man5\
			MAN8DIR=${DESTDIR:Q}${PREFIX:Q}/${PKGMANDIR:Q}/man8\
			LIBS=${LIBS:Q}

INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} CONFDIR=${DESTDIR:Q}${EXAMPLES_DIR:Q}
BUILD_MAKE_FLAGS=	${MAKE_FLAGS:S,${DESTDIR},,} CONFDIR=${PKG_SYSCONFDIR:Q}

CFLAGS.SunOS+=		-Dsolaris2
CFLAGS+=		-DDEVICE_GROUP=${ROOT_GROUP}

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "SunOS"
LIBS+=			-lutil
.endif

USE_TOOLS+=		makeinfo perl:run

INFO_FILES=		yes
PKG_SYSCONFSUBDIR=	mgetty+sendfax

.for cfg in		dialin.config		\
			faxheader		\
			faxrunq.config		\
			faxspool.rules.sample	\
			login.config		\
			mgetty.config		\
			voice.conf

CONF_FILES+=		${EXAMPLES_DIR}/${cfg} ${PKG_SYSCONFDIR}/${cfg}
.endfor

PKG_GROUPS=		dialer
PKG_USERS=		fax:dialer

USERGROUP_PHASE=	pre-install

EXAMPLES_DIR=		${PREFIX}/share/examples/mgetty+sendfax
OWN_DIRS_PERMS+=	/var/spool/fax ${ROOT_USER} ${ROOT_GROUP} 755
OWN_DIRS_PERMS+=	/var/spool/fax/incoming ${ROOT_USER} ${ROOT_GROUP} 755
OWN_DIRS_PERMS+=	/var/spool/fax/outgoing fax ${ROOT_GROUP} 755

SUBST_CLASSES+=		prefix
SUBST_FILES.prefix=	faxrunq.config policy.h
SUBST_SED.prefix=	-e 's|/usr/local|${PREFIX}|'
SUBST_STAGE.prefix=	pre-configure
SUBST_MESSAGE.prefix=	Fixing hardcoded installation prefix.

.include "../../graphics/netpbm/buildlink3.mk"

post-extract:
	cd ${WRKSRC} && cp policy.h-dist policy.h

do-configure:
	mv ${WRKSRC}/doc/fax.1in ${WRKSRC}/doc/sendfax.1in

.include "../../mk/bsd.pkg.mk"
