# $NetBSD: Makefile,v 1.36 2003/07/17 21:45:58 grant Exp $

DISTNAME=	exim-4.10
PKGREVISION=	1
CATEGORIES=	mail net
MASTER_SITES=	ftp://ftp.exim.org/pub/exim/exim4/ \
		ftp://ftp.csx.cam.ac.uk/pub/software/email/exim/exim4/ \
		ftp://ftp.esat.net/pub/networking/mail/mta/exim/exim4/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ad@NetBSD.org
HOMEPAGE=	http://www.exim.org/
COMMENT=	The Exim mail transfer agent, a replacement for sendmail

USE_PERL5=	yes
USE_BUILDLINK2=	yes

MAKE_ENV+=	SSLBASE=${SSLBASE:Q}

DEPENDS+=       exim-user>=4.10:../../mail/exim-user

pre-patch:
	${MKDIR} ${WRKSRC}/Local
	${CP} ${WRKSRC}/src/EDITME ${WRKSRC}/Local/Makefile.netbsd

pre-configure:
	${SED} -e 's:@PREFIX@:${PREFIX}:' \
	    < ${WRKSRC}/Local/Makefile.netbsd \
	    > ${WRKSRC}/Local/Makefile

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/etc/exim
	${INSTALL_DATA_DIR} /var/log/exim
	${CHMOD} 750 /var/log/exim
	strip ${WRKSRC}/build-*/exim
	strip ${WRKSRC}/build-*/exim_dbmbuild
	strip ${WRKSRC}/build-*/exim_tidydb
	strip ${WRKSRC}/build-*/exim_fixdb
	strip ${WRKSRC}/build-*/exim_dumpdb
	strip ${WRKSRC}/build-*/exim_lock

post-install:
	${SED} -e 's:@PREFIX@:${PREFIX}:' \
	    ${FILESDIR}/exim \
	    > ${PREFIX}/etc/rc.d/exim
	${SED} -e 's:@PREFIX@:${PREFIX}:' \
	    ${FILESDIR}/exim_newaliases \
	    > ${PREFIX}/sbin/exim_newaliases
	${CHMOD} ugo+x ${PREFIX}/sbin/exim_newaliases
	${SED} -e 's:@PREFIX@:${PREFIX}:' \
	    ${FILESDIR}/mailer.conf.exim \
	    > ${PREFIX}/etc/exim/mailer.conf.exim

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
