# $NetBSD: Makefile,v 1.37 2003/08/02 17:00:08 jmmv Exp $

DISTNAME=	exim-4.10
PKGREVISION=	2
CATEGORIES=	mail net
MASTER_SITES=	ftp://ftp.exim.org/pub/exim/exim4/ \
		ftp://ftp.csx.cam.ac.uk/pub/software/email/exim/exim4/ \
		ftp://ftp.esat.net/pub/networking/mail/mta/exim/exim4/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ad@NetBSD.org
HOMEPAGE=	http://www.exim.org/
COMMENT=	The Exim mail transfer agent, a replacement for sendmail

DEPENDS+=       exim-user>=4.10nb1:../../mail/exim-user

USE_PERL5=	yes
USE_BUILDLINK2=	yes
USE_PKGINSTALL=	yes

MAKE_ENV+=	SSLBASE=${SSLBASE:Q}

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		EXIM_GROUP EXIM_USER

PKG_SYSCONFSUBDIR=	exim
EGDIR=			${PREFIX}/share/examples/exim
CONF_FILES=		${EGDIR}/aliases ${PKG_SYSCONFDIR}/aliases
CONF_FILES+=		${EGDIR}/configure ${PKG_SYSCONFDIR}/configure
MESSAGE_SUBST+=		EGDIR="${EGDIR}"

RCD_SCRIPTS=		exim

OWN_DIRS_PERMS=		/var/log/exim ${EXIM_USER} ${EXIM_GROUP} 750

# XXX: The following will be handled by buildlink2 at some point.
CFLAGS+=		${_STRIPFLAG_CC}

pre-patch:
	${MKDIR} ${WRKSRC}/Local
	${CP} ${WRKSRC}/src/EDITME ${WRKSRC}/Local/Makefile.netbsd

pre-configure:
	${SED} -e 's:@PREFIX@:${PREFIX}:g' \
	    -e 's:@PKG_SYSCONFDIR@:${PKG_SYSCONFDIR}:g' \
	    -e 's:@EXIM_USER@:${EXIM_USER}:g' \
	    -e 's:@EXIM_GROUP@:${EXIM_GROUP}:g' \
	    < ${WRKSRC}/Local/Makefile.netbsd \
	    > ${WRKSRC}/Local/Makefile
	${SED} -e 's:@PREFIX@:${PREFIX}:g' \
	    -e 's:@PKG_SYSCONFDIR@:${PKG_SYSCONFDIR}:g' \
	    < ${WRKSRC}/src/configure.default \
	    > ${WRKSRC}/src/configure.default.new
	${MV} ${WRKSRC}/src/configure.default.new \
	    ${WRKSRC}/src/configure.default

post-build:
	${SED} -e 's:@PREFIX@:${PREFIX}:' \
	    ${FILESDIR}/exim_newaliases \
	    > ${WRKDIR}/exim_newaliases
	${SED} -e 's:@PREFIX@:${PREFIX}:' \
	    ${FILESDIR}/mailer.conf.exim \
	    > ${WRKDIR}/mailer.conf

pre-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/exim_newaliases ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKDIR}/mailer.conf ${EGDIR}

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
