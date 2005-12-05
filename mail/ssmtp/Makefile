# $NetBSD: Makefile,v 1.16 2005/12/05 23:55:11 rillig Exp $
#
# TLS functionality needs testing. Please let me know the result,
# and preferably info about your system.
#
# pkg@pop.707.to
# Toru TAKAMIZU

DISTNAME=	ssmtp_2.61.orig
PKGNAME=	ssmtp-2.61
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/s/ssmtp/}

MAINTAINER=	pkg@pop.707.to
HOMEPAGE=	http://packages.debian.org/testing/mail/ssmtp.html
COMMENT=	Extremely simple MTA to forward mail to a mail hub

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV:S/.orig$//}
USE_TOOLS+=		gmake
USE_PKGINSTALL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE:Q}

.include "options.mk"

PKG_SYSCONFSUBDIR=	${PKGBASE}
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=	${EGDIR}/ssmtp.conf ${PKG_SYSCONFDIR}/ssmtp.conf
CONF_FILES+=	${EGDIR}/revaliases ${PKG_SYSCONFDIR}/revaliases

post-extract:
	@${RM} -rf ${WRKSRC}/RCS

post-patch:
	for f in ${WRKSRC}/ssmtp.c ${WRKSRC}/ssmtp.conf ; do		\
		${MV} -f $$f $$f.orig ;					\
		${SED} "s,/etc/ssl/certs/,${PKG_SYSCONFDIR}/,g"		\
			$${f}.orig > $${f} ;				\
		${RM} -f $$f.orig ;					\
	done
	for f in ${WRKSRC}/ssmtp.8 ; do					\
		${MV} -f $$f $$f.orig ;					\
		${SED} "s,/etc/ssmtp/,${PKG_SYSCONFDIR}/,g"		\
			$$f.orig > $$f ; 				\
		${RM} -f $$f.orig ;					\
	done

post-build:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/mailer.conf		\
		> ${WRKDIR}/mailer.conf

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/ssmtp.conf ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/revaliases ${EGDIR}
	${INSTALL_DATA} ${WRKDIR}/mailer.conf ${EGDIR}

.include "../../mk/bsd.pkg.mk"
