# $NetBSD: Makefile,v 1.6 2001/04/27 13:52:18 abs Exp $
#

DISTNAME=	smtpd-2.0
CATEGORIES=	mail security
MASTER_SITES=	ftp://ftp.obtuse.com/pub/smtpd/

PATCHFILES=	patch-smtpd-2.0-RBL.gz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.obtuse.com/smtpd.html
COMMENT=	Store and forward SMTP proxy

SPOOL=		/var/spool/smtpd

pre-install:
		-${INSTALL_DATA_DIR} ${SPOOL}/etc
		for f in antirelay_check_rules_example antispam_check_rules.example smtpd_check_rules.example ; do ${INSTALL_DATA} ${WRKSRC}/$$f ${SPOOL}/etc; done
		${CHOWN} -R uucp.mail ${SPOOL}
		${CHMOD} -R g=,o= ${SPOOL}
		${CP} /etc/localtime /etc/resolv.conf ${SPOOL}/etc

post-install:
	@${INSTALL_DATA_DIR} ${PREFIX}/share/doc/smtpd
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/smtpd
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/smtpd

.include "../../mk/bsd.pkg.mk"
