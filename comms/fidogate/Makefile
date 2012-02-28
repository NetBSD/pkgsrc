# $NetBSD: Makefile,v 1.63 2012/02/28 11:21:50 hans Exp $
#

DISTNAME=	fidogate-4.4.10
PKGREVISION=	3
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fidogate/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fidogate.org/
COMMENT=	FidoNet (FTN) <-> Internet mail and news gateway

MAKE_JOBS_SAFE=		no

USE_TOOLS+=		gmake makeinfo perl:run yacc
MAKE_ENV+=		DEBUG="${CFLAGS} -Werror"
BUILDLINK_SETENV.CC=	CC="cc ${_STRIPFLAG_CC}"

EGDIR=		${PREFIX}/share/examples/fidogate
CONF_FILES=	${EGDIR}/fidogate.conf ${PKG_SYSCONFDIR}/fidogate/fidogate.conf
RCD_SCRIPTS=	fidogate
RCD_SCRIPT_SRC.fidogate=	${WRKSRC}/scripts/maintenance/rc.fidogate
INFO_FILES=	yes # PLIST

USERGROUP_PHASE=	pre-install
PKG_GROUPS=	news
PKG_USERS=	news:news
PKG_GECOS.news=	Network News
PKG_HOME.news=	/var/spool/news

NO_CONFIGURE=	yes

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	config.make
SUBST_SED.paths=	-e "s,@PREFIX@,"${PREFIX:Q}",g"
SUBST_SED.paths+=	-e "s,@PKG_SYSCONFDIR@,"${PKG_SYSCONFDIR:Q}",g"
SUBST_SED.paths+=	-e "s,@PKGINFODIR@,"${PKGINFODIR:Q}",g"
SUBST_SED.paths+=	-e "s,@PERL@,"${TOOLS_PATH.perl:Q}",g"
SUBST_STAGE.paths=	pre-build

# Too many schar/uchar issues.
BUILDLINK_TRANSFORM+=	rm:-Werror

PKG_DESTDIR_SUPPORT=	destdir

OWN_DIRS=		${PKG_SYSCONFDIR}/fidogate
INSTALLATION_DIRS+=	${EGDIR}		lib/fidogate		\
			lib/fidogate/bin	share/doc/fidogate	\
			share/fidogate		share/fidogate/sendmail	\
			info \
			share/fidogate/sendmail/mailer share/examples/rc.d

post-extract:
	${CP} ${WRKSRC}/examples/orodruin/fidogate.conf \
		${WRKSRC}/fidogate.conf.dist

pre-build:
	${RM} -f ${WRKSRC}/doc/fidogate.info*
	cd ${WRKSRC}/doc && makeinfo fidogate.texi && \
		${TOUCH} fidogate.txt html/fidogate_toc.html
	${PERL5} ${WRKSRC}/subst.pl -t${WRKSRC} ${WRKSRC}/fidogate.conf.dist \
		>${WRKSRC}/fidogate.conf

post-install:
	cd ${WRKSRC}/examples && for f in `${FIND} [m-p]* -type d -print`; do \
		${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/fidogate/$$f; done
	cd ${WRKSRC}/examples && for f in `${FIND} README [m-p]* -type f -print`; do \
		${INSTALL_DATA} $$f ${DESTDIR}${PREFIX}/share/examples/fidogate/$$f; done
	cd ${WRKSRC}/sendmail/mailer && ${INSTALL_DATA} ffx.m4 ftn.m4 \
		${DESTDIR}${PREFIX}/share/fidogate/sendmail/mailer
	${INSTALL_DATA} ${WRKSRC}/doc/fidogate.txt ${DESTDIR}${PREFIX}/share/doc/fidogate
	${INSTALL_DATA} ${WRKSRC}/fidogate.conf ${DESTDIR}${EGDIR}

.include "../../mk/bsd.pkg.mk"
