# $NetBSD: Makefile,v 1.4 2001/02/17 17:50:08 wiz Exp $
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
		-${MKDIR} ${SPOOL}/etc
		for f in antirelay_check_rules_example antispam_check_rules.example smtpd_check_rules.example ; do ${INSTALL_DATA} ${WRKSRC}/$$f ${SPOOL}/etc; done
		${CHOWN} -R uucp.mail ${SPOOL}
		${CHMOD} -R g=,o= ${SPOOL}
		${CP} /etc/localtime /etc/resolv.conf ${SPOOL}/etc

.include "../../mk/bsd.pkg.mk"
