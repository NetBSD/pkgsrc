# $NetBSD: Makefile,v 1.1.1.1 2008/09/08 22:11:05 abs Exp $
#

DISTNAME=	Mail-IMAPClient-2.2.9
PKGNAME=	p5-${DISTNAME:C:-2:2-2:}
SVR4_PKGNAME=	p5mic
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~markov/Mail-IMAPClient/
COMMENT=	Perl5 module for talking to RFC-2060 IMAP servers

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Digest-HMAC-[0-9]*:../../security/p5-Digest-HMAC
DEPENDS+=	p5-File-Temp>=0.18:../../devel/p5-File-Temp
DEPENDS+=	p5-Parse-RecDescent>=1.94:../../devel/p5-Parse-RecDescent
DEPENDS+=	p5-Test-Pod-[0-9]*:../../devel/p5-Test-Pod

PERL5_PACKLIST=		auto/Mail/IMAPClient2/.packlist

SUBST_CLASSES+=         conf
SUBST_STAGE.conf=       pre-configure
SUBST_FILES.conf=	BodyStructure/BodyStructure.pm \
			BodyStructure/Makefile.PL \
			BodyStructure/Parse/Makefile.PL \
			BodyStructure/Parse/Parse.grammar_new \
			BodyStructure/Parse/Parse.grammar_old \
			BodyStructure/Parse/Parse.pod \
			BodyStructure/Parse/t/parse.t \
			BodyStructure/t/bodystructure.t \
			Changes \
			IMAPClient.pm \
			IMAPClient.pod \
			INSTALL \
			INSTALL_perl5.80 \
			MANIFEST \
			Makefile.PL \
			MessageSet/Makefile.PL \
			MessageSet/MessageSet.pm \
			MessageSet/t/range.t \
			README \
			Thread/Makefile.PL \
			Thread/Thread.pod \
			Thread/t/thread.t \
			Todo \
			examples/build_dist.pl \
			examples/build_ldif.pl \
			examples/cleanTest.pl \
			examples/copy_folder.pl \
			examples/cyrus_expire.pl \
			examples/cyrus_expunge.pl \
			examples/find_dup_msgs.pl \
			examples/imap_to_mbox.pl \
			examples/imtestExample.pl \
			examples/migrate_mail2.pl \
			examples/migrate_mbox.pl \
			examples/populate_mailbox.pl \
			examples/sharedFolder.pl \
			t/basic.t \
			t/cram-md5.t
SUBST_SED.conf=         -e "s:IMAPClient:IMAPClient2:g"
SUBST_MESSAGE.conf=     Replacing IMAPClient with IMAPClient2

pre-configure:
	mv ${WRKSRC}/IMAPClient.pm ${WRKSRC}/IMAPClient2.pm
	mv ${WRKSRC}/IMAPClient.pod ${WRKSRC}/IMAPClient2.pod
	cd ${WRKSRC} && ${TOUCH} ${TOUCH_FLAGS} test.txt

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
