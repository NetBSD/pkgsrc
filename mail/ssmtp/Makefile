# $NetBSD: Makefile,v 1.3 2003/11/12 03:39:41 jschauma Exp $
# FreeBSD Id: ports/mail/ssmtp/Makefile,v 1.10 2003/04/14 08:41:04 leeym Exp
#
# TLS functionality needs testing. Please let me know the result,
# and preferably info about your system.
#
# pkg@pop.707.to
# Toru TAKAMIZU

DISTNAME=	ssmtp_2.60.3
PKGNAME=	ssmtp-2.60.3
PKGREVISION=	1
WRKSRC=		${WRKDIR}/${PKGBASE}-${PKGVERSION:C/([0-9]+.[0-9]+)(.[0-9]+)$/\1/}
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/s/ssmtp/}

MAINTAINER=	pkg@pop.707.to
HOMEPAGE=	http://packages.debian.org/testing/mail/ssmtp.html
COMMENT=	Extremely simple MTA to forward mail to a mail hub

USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES

USE_GMAKE=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-ssl --enable-inet6

PKG_SYSCONFSUBDIR=	${PKGBASE}
EGDIR=			${PREFIX}/share/examples/${PKGBASE}

CONF_FILES=	${EGDIR}/ssmtp.conf ${PKG_SYSCONFDIR}/ssmtp.conf
CONF_FILES+=	${EGDIR}/revaliases ${PKG_SYSCONFDIR}/revaliases

post-extract:
	${RM} -rf ${WRKSRC}/RCS

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
	${SED} ${FILES_SUBST_SED} ${FILESDIR}/mailer.conf		\
		> ${WRKDIR}/mailer.conf

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/ssmtp.conf ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/revaliases ${EGDIR}
	${INSTALL_DATA} ${WRKDIR}/mailer.conf ${EGDIR}

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
