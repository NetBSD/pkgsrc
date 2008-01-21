# $NetBSD: sites.mk,v 1.38 2008/01/21 02:15:45 obache Exp $
#
# This Makefile fragment defines read-only MASTER_SITE_* variables
# representing some well-known master distribution sites for software.
#

MASTER_SITE_XCONTRIB+=  \
	ftp://ftp.gwdg.de/pub/x11/x.org/contrib/ \
	ftp://sunsite.icm.edu.pl/pub/X11/contrib/ \
	ftp://mirror.switch.ch/mirror/X11/contrib/ \
	ftp://ftp.cica.es/pub/X/contrib/ \
	ftp://ftp.x.org/contrib/

MASTER_SITE_GNU+=       \
	http://ftp.gnu.org/pub/gnu/ \
	ftp://ftp.gnu.org/pub/gnu/ \
	ftp://ftp.funet.fi/pub/gnu/prep/ \
	ftp://ftp.kddlabs.co.jp/pub/gnu/gnu/ \
	ftp://ftp.dti.ad.jp/pub/GNU/ \
	ftp://ftp.informatik.hu-berlin.de/pub/gnu/ \
	ftp://ftp.lip6.fr/pub/gnu/ \
	ftp://ftp.tuwien.ac.at/linux/gnu/gnusrc/ \
	ftp://ftp.chg.ru/pub/gnu/

MASTER_SITE_GNUSTEP+=   \
	ftp://ftp.gnustep.org/pub/gnustep/ \
	ftp://ftp.easynet.nl/mirror/GNUstep/pub/gnustep/ \
	http://ftp.easynet.nl/mirror/GNUstep/pub/gnustep/

MASTER_SITE_PERL_CPAN+= \
	ftp://cpan.pair.com/modules/by-module/ \
	ftp://ftp.funet.fi/pub/languages/perl/CPAN/modules/by-module/ \
	ftp://ftp.gmd.de/mirrors/CPAN/modules/by-module/ \
	ftp://ftp.tuwien.ac.at/pub/CPAN/modules/by-module/ \
	http://cpan.perl.org/CPAN/modules/by-module/ \
	ftp://ftp.fi.muni.cz/pub/CPAN/modules/by-module/

MASTER_SITE_R_CRAN+=    \
	http://cran.r-project.org/src/ \
	ftp://cran.r-project.org/pub/R/src/ \
	http://cran.at.r-project.org/src/ \
	ftp://cran.at.r-project.org/pub/R/src/ \
	http://cran.ch.r-project.org/src/ \
	http://cran.uk.r-project.org/src/ \
	http://cran.us.r-project.org/src/ \
	http://lib.stat.cmu.edu/R/CRAN/src/ \
	ftp://ftp.u-aizu.ac.jp/pub/lang/R/CRAN/src/ \
	http://stat.ethz.ch/CRAN/src/ \
	http://www.stats.bris.ac.uk/R/src/

MASTER_SITE_TEX_CTAN+= \
	ftp://ftp.funet.fi/pub/TeX/CTAN/ \
	ftp://ftp.tex.ac.uk/tex-archive/ \
	ftp://ftp.dante.de/tex-archive/ \
	ftp://www.t.ring.gr.jp/pub/text/CTAN/ \
	http://www.t.ring.gr.jp/archives/text/CTAN/

MASTER_SITE_SUNSITE+=   \
	ftp://sunsite.unc.edu/pub/Linux/ \
	ftp://ftp.chg.ru/pub/Linux/sunsite/ \
	ftp://ftp.kddlabs.co.jp/Linux/metalab.unc.edu/ \
	ftp://ftp.icm.edu.pl/pub/Linux/sunsite/ \
	ftp://ftp.nvg.ntnu.no/pub/mirrors/metalab.unc.edu/ \
	ftp://ftp.lip6.fr/pub/linux/sunsite/ \
	ftp://ftp.cs.tu-berlin.de/pub/linux/Mirrors/sunsite.unc.edu/ \
	ftp://ftp.tuwien.ac.at/pub/linux/ibiblio/

MASTER_SITE_GNOME+=     \
	http://ftp.gnome.org/pub/GNOME/ \
	ftp://ftp.gnome.org/pub/GNOME/ \
	ftp://ftp.sunet.se/pub/X11/GNOME/ \
	ftp://ftp.tuwien.ac.at/hci/GNOME/ \
	ftp://ftp.cse.buffalo.edu/pub/Gnome/ \
	ftp://ftp.dti.ad.jp/pub/X/gnome/ \
	ftp://ftp.kddlabs.co.jp/pub/GNOME/ \
	ftp://ftp.chg.ru/pub/X11/gnome/ \
	ftp://ftp.dit.upm.es/linux/gnome/ \
	ftp://sunsite.mff.cuni.cz/pub/GNOME/

MASTER_SITE_KDE+=	\
	ftp://ftp.kde.org/pub/kde/stable/ \
	http://ftp.scarlet.be/pub/kde/stable/ \
	ftp://www.t.ring.gr.jp/pub/X/kde/stable/ \
	http://www.t.ring.gr.jp/archives/X/kde/stable/ \
	ftp://ftp.kddlabs.co.jp/pub/X/kde/stable/ \
	ftp://ftp.planetmirror.com.au/pub/kde/stable/ \
	http://public.planetmirror.com/pub/kde/stable/ \
	http://mirrors.isc.org/pub/kde/stable/ \
	ftp://ftp.oregonstate.edu/pub/kde/stable/ \
	ftp://ftp.gtlib.cc.gatech.edu/pub/kde/stable/ \
	ftp://kde.mirrors.tds.net/pub/kde/stable/ \
	ftp://gd.tuwien.ac.at/kde/stable/ \
	ftp://ftp.solnet.ch/mirror/KDE/stable/ \
	ftp://ftp-stud.fht-esslingen.de/pub/Mirrors/ftp.kde.org/pub/kde/stable/ \
	ftp://mirrors.dotsrc.org/kde/stable/ \
	ftp://ftp.fi.muni.cz/pub/kde/stable/

# see http://sourceforge.net/project/mirror_picker.php
MASTER_SITE_SOURCEFORGE+=	\
	http://dfn.dl.sourceforge.net/sourceforge/ \
	http://easynews.dl.sourceforge.net/sourceforge/ \
	http://heanet.dl.sourceforge.net/sourceforge/ \
	http://garr.dl.sourceforge.net/sourceforge/ \
	http://internap.dl.sourceforge.net/sourceforge/ \
	http://jaist.dl.sourceforge.net/sourceforge/ \
	http://kent.dl.sourceforge.net/sourceforge/ \
	http://mesh.dl.sourceforge.net/sourceforge/ \
	http://nchc.dl.sourceforge.net/sourceforge/ \
	http://optusnet.dl.sourceforge.net/sourceforge/ \
	http://superb-east.dl.sourceforge.net/sourceforge/ \
	http://superb-west.dl.sourceforge.net/sourceforge/ \
	http://surfnet.dl.sourceforge.net/sourceforge/ \
	http://switch.dl.sourceforge.net/sourceforge/ \
	http://ufpr.dl.sourceforge.net/sourceforge/ \
	http://belnet.dl.sourceforge.net/sourceforge/

MASTER_SITE_SOURCEFORGE_JP+=	\
	http://osdn.dl.sourceforge.jp/ \
	http://jaist.dl.sourceforge.jp/ \
	http://keihanna.dl.sourceforge.jp/ \
	http://globalbase.dl.sourceforge.jp/ \
	http://iij.dl.sourceforge.jp/ \
	http://download.sourceforge.jp/

MASTER_SITE_SUSE+=	\
	ftp://rpmfind.net/linux/SuSE-Linux/${MACHINE_ARCH}/update/${SUSE_VERSION}/ \
	ftp://fr.rpmfind.net/linux/SuSE-Linux/${MACHINE_ARCH}/update/${SUSE_VERSION}/ \
	ftp://fr2.rpmfind.net/linux/SuSE-Linux/${MACHINE_ARCH}/update/${SUSE_VERSION}/

MASTER_SITE_MOZILLA_ALL+=   \
	http://ftp.mozilla.org/pub/mozilla.org/ \
	ftp://ftp.mozilla.org/pub/mozilla.org/ \
	ftp://ftp.belnet.be/mirror/ftp.mozilla.org/

MASTER_SITE_MOZILLA+=	\
	http://ftp.mozilla.org/pub/mozilla.org/ \
	ftp://ftp.mozilla.org/pub/mozilla.org/ \
	http://releases.mozilla.org/pub/mozilla.org/ \
	ftp://releases.mozilla.org/pub/mozilla.org/ \
	http://mozilla.isc.org/pub/mozilla.org/ \
	ftp://mozilla.isc.org/pub/mozilla.org/ \
	http://mozilla.ussg.indiana.edu/pub/mozilla.org/ \
	ftp://mozilla.ussg.indiana.edu/pub/mozilla.org/ \
	http://mozilla.osuosl.org/pub/mozilla.org/ \
	ftp://ftp.osuosl.org/pub/mozilla.org/ \
	http://mozilla.cs.utah.edu/pub/mozilla.org/ \
	ftp://mozilla.cs.utah.edu/pub/mozilla.org/ \
	http://mozilla.mirrors.tds.net/pub/mozilla.org/ \
	ftp://mozilla.mirrors.tds.net/pub/mozilla.org/ \
	ftp://ftp.scarlet.be/pub/mozilla.org/ \
	http://ftp.scarlet.be/pub/mozilla.org/ \
	ftp://ftp.uni-erlangen.de/pub/mozilla.org/ \
	http://ftp.uni-erlangen.de/pub/mozilla.org/ \
	http://sunsite.rediris.es/pub/mozilla.org/ \
	ftp://sunsite.rediris.es/pub/mozilla.org/

MASTER_SITE_XEMACS+=    \
	ftp://ftp.xemacs.org/pub/xemacs/ \
	ftp://ftp.dti.ad.jp/pub/unix/editor/xemacs/ \
	ftp://ftp.pasteur.fr/pub/computing/xemacs/ \
	http://public.planetmirror.com.au/pub/xemacs/ \
	ftp://mirror.aarnet.edu.au/pub/xemacs/ \
	ftp://mirror.cict.fr/xemacs/ \
	ftp://ftp.t.ring.gr.jp/pub/text/xemacs/ \
	ftp://ftp.mpi-sb.mpg.de/pub/gnu/mirror/ftp.xemacs.org/xemacs/

MASTER_SITE_APACHE+=    \
	http://www.apache.org/dist/ \
	http://mirrors.ccs.neu.edu/Apache/dist/ \
	http://apache.planetmirror.com.au/dist/ \
	http://www.ibiblio.org/pub/mirrors/apache/ \
	http://apache.oregonstate.edu/ \
	http://apache.secsup.org/dist/ \
	http://apache.osuosl.org/ \
	http://www.mirrorservice.org/sites/ftp.apache.org/ \
	ftp://ftp.ccs.neu.edu/net/mirrors/Apache/dist/ \
	ftp://ftp.planetmirror.com.au/pub/apache/dist/ \
	ftp://www.ibiblio.org/pub/mirrors/apache/ \
	ftp://ftp.oregonstate.edu/pub/apache/ \
	ftp://apache.secsup.org/pub/apache/dist/

MASTER_SITE_MYSQL+=	\
	ftp://ftp.easynet.be/mysql/Downloads/	\
	ftp://ftp.fi.muni.cz/pub/mysql/Downloads/	\
	http://mysql.mirrors.cybercity.dk/Downloads/	\
	ftp://ftp.fh-wolfenbuettel.de/pub/database/mysql/Downloads/	\
	ftp://ftp.gwdg.de/pub/misc/mysql/Downloads/	\
	http://mirrors.ntua.gr/MySQL/Downloads/		\
	ftp://ftp.ntua.gr/pub/databases/mysql/Downloads/	\
	http://mysql.sote.hu/Downloads/	\
	ftp://ftp.rhnet.is/pub/mysql/Downloads/	\
	ftp://mirror.widexs.nl/pub/mysql/Downloads/	\
	ftp://mirror.switch.ch/mirror/mysql/Downloads/	\
	http://mysql.dp.ua/Downloads/	\
	http://mysql.mirrored.ca/Downloads/	\
	ftp://mirror.services.wisc.edu/mirrors/mysql/Downloads/	\
	ftp://ftp.orst.edu/pub/mysql/Downloads/	\
	http://mysql.mirrors.pair.com/Downloads/	\
	ftp://ftp.linorg.usp.br/mysql/Downloads/	\
	ftp://ftp.cbn.net.id/mirror/mysql/Downloads/	\
	http://download.softagency.net/MySQL/Downloads/

MASTER_SITE_DEBIAN+= \
	http://ftp.debian.org/debian/ \
	http://ftp.at.debian.org/debian/ \
	http://ftp.au.debian.org/debian/ \
	http://ftp.wa.au.debian.org/debian/ \
	http://ftp.bg.debian.org/debian/ \
	http://ftp.cl.debian.org/debian/ \
	http://ftp.cz.debian.org/debian/ \
	http://ftp.de.debian.org/debian/ \
	http://ftp2.de.debian.org/debian/ \
	http://ftp.ee.debian.org/debian/ \
	http://ftp.es.debian.org/debian/ \
	http://ftp.fi.debian.org/debian/ \
	http://ftp.fr.debian.org/debian/ \
	http://ftp2.fr.debian.org/debian/ \
	http://ftp.uk.debian.org/debian/ \
	http://ftp.hr.debian.org/debian/ \
	http://ftp.ie.debian.org/debian/ \
	http://ftp.is.debian.org/debian/ \
	http://ftp.it.debian.org/debian/ \
	http://ftp.jp.debian.org/debian/ \
	http://ftp.nl.debian.org/debian/ \
	http://ftp.no.debian.org/debian/ \
	http://ftp.nz.debian.org/debian/ \
	http://ftp.pl.debian.org/debian/ \
	http://ftp.ru.debian.org/debian/ \
	http://ftp.se.debian.org/debian/ \
	http://ftp.si.debian.org/debian/ \
	http://ftp.sk.debian.org/debian/ \
	http://ftp.us.debian.org/debian/

MASTER_SITE_OPENOFFICE+=	\
	http://mirrors.isc.org/pub/openoffice/ \
	http://ftp.stardiv.de/pub/OpenOffice.org/ \
	http://openoffice.mirrors.ilisys.com.au/ \
	ftp://ftp.pucpr.br/openoffice/ \
	http://www.ibiblio.org/pub/mirrors/openoffice/ \
	ftp://ftp.ussg.iu.edu/pub/openoffice/ \
	http://openoffice.mirrors.pair.com/ftp/ \
	http://gd.tuwien.ac.at/office/openoffice/ \
	http://ftp.belnet.be/pub/mirror/ftp.openoffice.org/ \
	ftp://ftp.kulnet.kuleuven.ac.be/pub/mirror/openoffice.org/ \
	http://ftp.sh.cvut.cz/MIRRORS/OpenOffice/ \
	ftp://ftp.funet.fi/pub/mirrors/openoffice.org/ \
	ftp://openoffice.cict.fr/openoffice/ \
	http://ftp.club-internet.fr/pub/OpenOffice/ \
	ftp://sunsite.informatik.rwth-aachen.de/pub/mirror/OpenOffice/ \
	ftp://ftp.tu-chemnitz.de/pub/openoffice/ \
	ftp://ftp-stud.fht-esslingen.de/pub/Mirrors/ftp.openoffice.org/ \
	ftp://ftp.join.uni-muenster.de/pub/software/OpenOffice/ \
	http://ftp.ntua.gr/pub/OpenOffice/ \
	http://ftp.fsf.hu/OpenOffice.org/ \
	http://ftp.rhnet.is/pub/OpenOffice/ \
	http://na.mirror.garr.it/mirrors/openoffice/ \
	http://vlaai.snt.utwente.nl/pub/software/openoffice/ \
	http://niihau.student.utwente.nl/openoffice/ \
	http://borft.student.utwente.nl/openoffice/ \
	http://ftp.iasi.roedu.net/mirrors/openoffice.org/ \
	ftp://ftp.arnes.si/packages/OpenOffice.org/ \
	ftp://ftp.saix.net/pub/OpenOffice.org/ \
	http://ftp.rediris.es/ftp/mirror/openoffice.org/ \
	http://ftp.sunet.se/pub/Office/OpenOffice.org/ \
	ftp://mirror.switch.ch/mirror/OpenOffice/ \
	http://mirror.pacific.net.au/openoffice/ \
	http://public.planetmirror.com.au/pub/openoffice/ \
	http://komo.vlsm.org/openoffice/ \
	ftp://ftp.kddlabs.co.jp/office/openoffice/ \
	ftp://ftp.t.ring.gr.jp/pub/misc/openoffice/ \
	http://mymirror.asiaosc.org/openoffice/ \
	ftp://ftp.kr.freebsd.org/pub/openoffice/ \
	http://www.fs.tum.de/~mrauch/OpenOffice/download/

MASTER_SITE_CYGWIN+= \
	http://mirrors.kernel.org/sources.redhat.com/cygwin/ \
	http://mirrors.xmission.com/cygwin/ \
	ftp://ftp.t.ring.gr.jp/pub/pc/gnu-win32/ \
	ftp://ftp.funet.fi/pub/mirrors/cygwin.com/pub/cygwin/

MASTER_SITE_IFARCHIVE+= \
	http://ifarchive.flavorplex.com/if-archive/ \
	http://ifarchive.heanet.ie/if-archive/ \
	http://ifarchive.giga.or.at/if-archive/

### PGSQL list was last updated on 20080109
MASTER_SITE_PGSQL+=	\
	ftp://ftp.ar.postgresql.org/pub/mirrors/postgresql/ \
	ftp://ftp.at.postgresql.org/db/www.postgresql.org/pub/ \
	ftp://ftp.au.postgresql.org/pub/postgresql/ \
	ftp://ftp.ba.postgresql.org/pub/postgresql/ \
	ftp://ftp.be.postgresql.org/postgresql/ \
	ftp://ftp.ch.postgresql.org/mirror/postgresql/ \
	ftp://ftp.cl.postgresql.org/postgresql/ \
	ftp://ftp.cn.postgresql.org/pub/postgresql/ \
	ftp://ftp.cz.postgresql.org/pgsql/ \
	ftp://ftp.de.postgresql.org/mirror/postgresql/ \
	ftp://ftp.dk.postgresql.org/postgresql/ \
	ftp://ftp.ee.postgresql.org/pub/postgresql/ \
	ftp://ftp.fi.postgresql.org/pub/postgresql/ \
	ftp://ftp.fr.postgresql.org/ \
	ftp://ftp.gr.postgresql.org/pub/databases/postgresql/ \
	ftp://ftp.hk.postgresql.org/postgresql/ \
	ftp://ftp.ie.postgresql.org/mirrors/ftp.postgresql.org/pub/ \
	ftp://ftp.il.postgresql.org/ftp.postgresql.org/ \
	ftp://ftp.is.postgresql.org/pub/postgresql/ \
	ftp://ftp.jp.postgresql.org/ \
	ftp://ftp.kr.postgresql.org/postgresql/ \
	ftp://ftp.lt.postgresql.org/ \
	ftp://ftp.lv.postgresql.org/mirrors/ftp.postgresql.org/ \
	ftp://ftp.my.postgresql.org/pub/postgresql/ \
	ftp://ftp.nl.postgresql.org:21/pub/mirror/postgresql/ \
	ftp://ftp.no.postgresql.org/pub/databases/postgresql/ \
	ftp://ftp.nz.postgresql.org/postgresql/ \
	ftp://ftp.pt.postgresql.org/pub/postgresql/ \
	ftp://ftp.ru.postgresql.org/pub/mirrors/pgsql/ \
	ftp://ftp.se.postgresql.org/pub/databases/relational/postgresql/ \
	ftp://ftp.si.postgresql.org/pub/mirrors/postgresql/ \
	ftp://ftp.tr.postgresql.org/pub/PostgreSQL/ \
	ftp://ftp.tw.postgresql.org/pub/postgresql/ \
	ftp://ftp.ua.postgresql.org/pub/mirrors/postgresql.org/ \
	ftp://ftp.za.postgresql.org/mirror/ftp.postgresql.org/ \
	ftp://ftp10.de.postgresql.org/pub/mirror/postgresql/ \
	ftp://ftp10.us.postgresql.org/pub/postgresql/ \
	ftp://ftp11.us.postgresql.org/pub/mirrors/postgresql/ \
	ftp://ftp12.us.postgresql.org/postgresql/ \
	ftp://ftp2.au.postgresql.org/pub/postgresql/ \
	ftp://ftp2.be.postgresql.org/pub/postgresql/ \
	ftp://ftp2.br.postgresql.org/postgresql/ \
	ftp://ftp2.ch.postgresql.org/pub/mirrors/postgresql/ \
	ftp://ftp2.cz.postgresql.org/pub/postgresql/ \
	ftp://ftp2.gr.postgresql.org/pub/databases/postgresql/ \
	ftp://ftp2.ie.postgresql.org/mirrors/ftp.postgresql.org/ \
	ftp://ftp2.it.postgresql.org/mirrors/postgres/ \
	ftp://ftp2.jp.postgresql.org/pub/postgresql/ \
	ftp://ftp2.kr.postgresql.org/pub/postgresql/ \
	ftp://ftp2.lv.postgresql.org/postgresql/ \
	ftp://ftp2.nl.postgresql.org/mirror/postgresql/ \
	ftp://ftp2.sk.postgresql.org/pub/postgresql/ \
	ftp://ftp2.uk.postgresql.org/sites/ftp.postgresql.org/ \
	ftp://ftp3.de.postgresql.org/pub/Mirrors/ftp.postgresql.org/ \
	ftp://ftp3.fr.postgresql.org/pub/postgresql/ \
	ftp://ftp3.jp.postgresql.org/pub/db/postgresql/ \
	ftp://ftp3.ru.postgresql.org/pub/mirror/postgresql/pub/ \
	ftp://ftp3.tw.postgresql.org/pub/Unix/Database/postgresql/ \
	ftp://ftp4.fr.postgresql.org/pub/mirrors/postgresql/ \
	ftp://ftp4.nl.postgresql.org/postgresql.zeelandnet.nl/ \
	ftp://ftp4.tw.postgresql.org/pub/postgresql/ \
	ftp://ftp4.us.postgresql.org/pub/postgresql/ \
	ftp://ftp5.ca.postgresql.org/mirrors/postgresql/ \
	ftp://ftp5.es.postgresql.org/mirror/postgresql/ \
	ftp://ftp5.us.postgresql.org/pub/PostgreSQL/ \
	ftp://ftp6.it.postgresql.org/pub/PostgreSQL/ \
	ftp://ftp6.pl.postgresql.org/pub/postgresql/ \
	ftp://ftp6.ro.postgresql.org/pub/mirrors/ftp.postgresql.org/ \
	ftp://ftp7.de.postgresql.org/pub/ftp.postgresql.org/ \
	ftp://ftp7.it.postgresql.org/pub/unix/postgres/ \
	ftp://ftp7.pl.postgresql.org/pub/mirror/ftp.postgresql.org/ \
	ftp://ftp7.ro.postgresql.org/1/PostgreSQL/ \
	ftp://ftp7.ru.postgresql.org/pub/postgresql/ \
	ftp://ftp7.tr.postgresql.org/pub/postgresql/ \
	ftp://ftp7.us.postgresql.org/pub/postgresql/ \
	ftp://ftp8.de.postgresql.org/pub/misc/pgsql/ \
	ftp://ftp8.pl.postgresql.org/pub/postgresql/ \
	ftp://ftp8.us.postgresql.org/postgresql/ \
	ftp://ftp9.de.postgresql.org/unix/databases/postgresql/ \
	ftp://ftp9.id.postgresql.org/postgresql/ \
	ftp://ftp9.pl.postgresql.org/pub/mirrors/ftp.postgresql.org/ \
	ftp://ftp9.us.postgresql.org/pub/mirrors/postgresql/ \
	http://ftp.at.postgresql.org/db/www.postgresql.org/pub/ \
	http://ftp.be.postgresql.org/postgresql/ \
	http://ftp.cz.postgresql.org/ \
	http://ftp.de.postgresql.org/mirror/postgresql/ \
	http://ftp.dk.postgresql.org/postgresql/ \
	http://ftp.ee.postgresql.org/pub/postgresql/ \
	http://ftp.gr.postgresql.org/pub/databases/postgresql/ \
	http://ftp.ie.postgresql.org/mirrors/ftp.postgresql.org/pub/ \
	http://ftp.pt.postgresql.org/pub/postgresql/ \
	http://ftp.se.postgresql.org/pub/databases/relational/postgresql/ \
	http://ftp2.au.postgresql.org/pub/postgresql/ \
	http://ftp2.be.postgresql.org/ \
	http://ftp2.br.postgresql.org/postgresql/ \
	http://ftp2.ch.postgresql.org/pub/mirrors/postgresql/ \
	http://ftp2.cz.postgresql.org/pub/postgresql/ \
	http://ftp2.gr.postgresql.org/pub/databases/postgresql/ \
	http://ftp2.ie.postgresql.org/mirrors/ftp.postgresql.org/ \
	http://ftp2.it.postgresql.org/mirrors/postgres/ \
	http://ftp2.jp.postgresql.org/pub/postgresql/ \
	http://ftp2.lv.postgresql.org/ \
	http://ftp2.nl.postgresql.org/ \
	http://ftp2.uk.postgresql.org/sites/ftp.postgresql.org/ \
	http://ftp3.de.postgresql.org/pub/Mirrors/ftp.postgresql.org/ \
	http://ftp3.fr.postgresql.org/pub/postgresql/ \
	http://ftp3.jp.postgresql.org/pub/db/postgresql/ \
	http://ftp4.fr.postgresql.org/pub/mirrors/postgresql/ \
	http://ftp4.nl.postgresql.org/ \
	http://ftp4.tw.postgresql.org/ \
	http://ftp5.es.postgresql.org/mirror/postgresql/ \
	http://ftp6.pl.postgresql.org/pub/postgresql/ \
	http://ftp6.ro.postgresql.org/pub/mirrors/ftp.postgresql.org/ \
	http://ftp7.it.postgresql.org/pub/unix/postgres/ \
	http://ftp7.ru.postgresql.org/pub/postgresql/ \
	http://ftp7.us.postgresql.org/pub/postgresql/ \
	http://ftp8.de.postgresql.org/pub/misc/pgsql/ \
	http://ftp8.pl.postgresql.org/pub/postgresql/ \
	http://ftp8.us.postgresql.org/postgresql/ \
	http://ftp9.id.postgresql.org/ \
	http://ftp9.pl.postgresql.org/pub/mirrors/ftp.postgresql.org/ \
	http://ftp9.us.postgresql.org/pub/mirrors/postgresql/

MASTER_SITE_GENTOO+= \
	http://distro.ibiblio.org/pub/linux/distributions/gentoo/ \
	http://csociety-ftp.ecn.purdue.edu/pub/gentoo/ \
	http://gentoo.mirrors.pair.com/ \
	http://gentoo.chem.wisc.edu/gentoo/ \
	http://adelie.polymtl.ca/ \
	http://mirrors.tds.net/gentoo/ \
	http://ftp.belnet.be/mirror/rsync.gentoo.org/gentoo/ \
	http://ftp.easynet.nl/mirror/gentoo/ \
	http://ftp.snt.utwente.nl/pub/os/linux/gentoo/ \
	http://trumpetti.atm.tut.fi/gentoo/ \
	http://ds.thn.htu.se/linux/gentoo/ \
	http://sunsite.cnlab-switch.ch/ftp/mirror/gentoo/ \
	http://linux.rz.ruhr-uni-bochum.de/download/gentoo-mirror/ \
	http://mirrors.sec.informatik.tu-darmstadt.de/gentoo/ \
	http://ftp.uni-erlangen.de/pub/mirrors/gentoo/ \
	http://darkstar.ist.utl.pt/gentoo/ \
	http://ftp.caliu.info/pub/gentoo/ \
	http://gentoo.inode.at/ \
	http://ftp.rhnet.is/pub/gentoo/ \
	http://gentoo.mirror.sdv.fr/ \
	http://public.planetmirror.com/pub/gentoo/ \
	http://ftp.gentoo.or.kr/ \
	http://mirror.gentoo.gr.jp/ \
	http://gentoo.gg3.net/ \
	http://gentoo.kems.net/ \
	ftp://ftp.gtlib.cc.gatech.edu/pub/gentoo/ \
	ftp://csociety-ftp.ecn.purdue.edu/pub/gentoo/ \
	ftp://mirror.iawnet.sandia.gov/pub/gentoo/ \
	ftp://ftp.ussg.iu.edu/pub/linux/gentoo/ \
	ftp://ftp.ucsb.edu/pub/mirrors/linux/gentoo/ \
	ftp://gentoo.mirrors.pair.com/ \
	ftp://mirrors.tds.net/gentoo/ \
	ftp://ftp.belnet.be/mirror/rsync.gentoo.org/gentoo/ \
	ftp://ftp.easynet.nl/mirror/gentoo/ \
	ftp://ftp.snt.utwente.nl/pub/os/linux/gentoo/ \
	ftp://trumpetti.atm.tut.fi/gentoo/ \
	ftp://sunsite.cnlab-switch.ch/mirror/gentoo/ \
	ftp://ftp.join.uni-muenster.de/pub/linux/distributions/gentoo/ \
	ftp://ftp6.uni-muenster.de/pub/linux/distributions/gentoo/ \
	ftp://ftp.tu-clausthal.de/pub/linux/gentoo/ \
	ftp://sunsite.informatik.rwth-aachen.de/pub/Linux/gentoo/ \
	ftp://linux.rz.ruhr-uni-bochum.de/gentoo-mirror/ \
	ftp://ftp.uni-erlangen.de/pub/mirrors/gentoo/ \
	ftp://darkstar.ist.utl.pt/pub/gentoo/ \
	ftp://ftp.caliu.info/pub/gentoo/ \
	ftp://gentoo.inode.at/source/ \
	ftp://ftp.rhnet.is/pub/gentoo/ \
	ftp://files.gentoo.gr/ \
	ftp://ftp.planetmirror.com/pub/gentoo/ \
	ftp://ftp.ecc.u-tokyo.ac.jp/GENTOO/ \
	ftp://gentoo.kems.net/pub/mirrors/gentoo/

MASTER_SITE_FREEBSD+= \
	ftp://ftp.FreeBSD.org/pub/FreeBSD/distfiles/ \
	ftp://ftp.jp.FreeBSD.org/pub/FreeBSD/distfiles/

MASTER_SITE_FREEBSD_LOCAL+= \
	ftp://ftp.FreeBSD.org/pub/FreeBSD/ports/local-distfiles/ \
	ftp://ftp.jp.FreeBSD.org/pub/FreeBSD/ports/local-distfiles/

# The primary backup site.
MASTER_SITE_BACKUP?=	\
	ftp://ftp.fi.NetBSD.org/pub/NetBSD/packages/distfiles/ \
	ftp://ftp.NetBSD.org/pub/NetBSD/packages/distfiles/ \
	http://ftp.NetBSD.org/pub/NetBSD/packages/distfiles/ \
	ftp://ftp.FreeBSD.org/pub/FreeBSD/distfiles/
