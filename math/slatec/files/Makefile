LIB	= slatec

LIBDIR	= ${PREFIX}/lib

FORTRAN = %%FORTRAN%%

all:	lib$(LIB)

OBJ= aaaaaa.o acosh.o ai.o aie.o albeta.o algams.o ali.o alngam.o alnrel.o \
asinh.o asyik.o asyjy.o atanh.o avint.o bakvec.o balanc.o \
balbak.o bandr.o bandv.o bcrh.o bdiff.o besi.o besi0.o besi0e.o \
besi1.o besi1e.o besj.o besj0.o besj1.o besk.o besk0.o besk0e.o \
besk1.o besk1e.o beskes.o besknu.o besks.o besy.o besy0.o besy1.o \
besynu.o beta.o betai.o bfqad.o bi.o bie.o binom.o bint4.o bintk.o \
bisect.o bkias.o bkisr.o bksol.o blktr1.o blktri.o bndacc.o bndsol.o \
bnfac.o bnslv.o bqr.o bsgq8.o bskin.o bspdoc.o bspdr.o bspev.o \
bsplvd.o bsplvn.o bsppp.o bspvd.o bspvn.o bsqad.o bsrh.o bvalu.o \
bvder.o bvpor.o bvsup.o c0lgmc.o c1merg.o c9lgmc.o c9ln2r.o cacai.o \
cacon.o cacos.o cacosh.o cairy.o carg.o casin.o casinh.o casyi.o \
catan.o catan2.o catanh.o caxpy.o cbabk2.o cbal.o cbesh.o cbesi.o \
cbesj.o cbesk.o cbesy.o cbeta.o cbinu.o cbiry.o cbknu.o cblkt1.o \
cblktr.o cbrt.o cbuni.o cbunk.o ccbrt.o cchdc.o cchdd.o cchex.o \
cchud.o ccmpb.o ccopy.o ccosh.o ccot.o cdcdot.o cdcor.o cdcst.o cdiv.o \
cdntl.o cdntp.o cdotc.o cdotu.o cdpsc.o cdpst.o cdriv1.o cdriv2.o \
cdriv3.o cdscl.o cdstp.o cdzro.o cexprl.o cfftb.o cfftb1.o cfftf.o \
cfftf1.o cffti.o cffti1.o cfod.o cg.o cgamma.o cgamr.o cgbco.o cgbdi.o \
cgbfa.o cgbmv.o cgbsl.o cgeco.o cgedi.o cgeev.o cgefa.o cgefs.o \
cgeir.o cgemm.o cgemv.o cgerc.o cgeru.o cgesl.o cgtsl.o ch.o chbmv.o \
chemm.o chemv.o cher.o cher2.o cher2k.o cherk.o chfcm.o chfdv.o \
chfev.o chfie.o chico.o chidi.o chiev.o chifa.o chisl.o chkder.o \
chkpr4.o chkprm.o chksn4.o chksng.o chpco.o chpdi.o chpfa.o chpmv.o \
chpr.o chpr2.o chpsl.o chu.o cinvit.o ckscl.o clbeta.o clngam.o \
clnrel.o clog10.o cmgnbn.o cmlri.o cmpcsg.o cmposd.o cmposn.o cmposp.o \
cmptr3.o cmptrx.o cnbco.o cnbdi.o cnbfa.o cnbfs.o cnbir.o cnbsl.o \
combak.o comhes.o comlr.o comlr2.o compb.o comqr.o comqr2.o cortb.o \
corth.o cosdg.o cosgen.o cosqb.o cosqb1.o cosqf.o cosqf1.o cosqi.o \
cost.o costi.o cot.o cpadd.o cpbco.o cpbdi.o cpbfa.o cpbsl.o cpevl.o \
cpevlr.o cpoco.o cpodi.o cpofa.o cpofs.o cpoir.o cposl.o cppco.o \
cppdi.o cppfa.o cppsl.o cpqr79.o cproc.o cprocp.o cprod.o cprodp.o \
cpsi.o cptsl.o cpzero.o cqrdc.o cqrsl.o crati.o crotg.o cs1s2.o \
cscal.o cscale.o cseri.o csevl.o cshch.o csico.o csidi.o csifa.o \
csinh.o csisl.o cspco.o cspdi.o cspfa.o cspsl.o csroot.o csrot.o \
csscal.o csvdc.o cswap.o csymm.o csyr2k.o csyrk.o ctan.o ctanh.o \
ctbmv.o ctbsv.o ctpmv.o ctpsv.o ctrco.o ctrdi.o ctrmm.o ctrmv.o \
ctrsl.o ctrsm.o ctrsv.o cuchk.o cunhj.o cuni1.o cuni2.o cunik.o \
cunk1.o cunk2.o cuoik.o cv.o cwrsk.o d1mach.o d1merg.o d1mpyq.o \
d1updt.o d9aimp.o d9atn1.o d9b0mp.o d9b1mp.o d9chu.o d9gmic.o d9gmit.o \
d9knus.o d9lgic.o d9lgit.o d9lgmc.o d9ln2r.o d9pak.o d9upak.o dacosh.o \
dai.o daie.o dasinh.o dasum.o dasyik.o dasyjy.o datanh.o davint.o \
daws.o daxpy.o dbcg.o dbdiff.o dbesi.o dbesi0.o dbesi1.o dbesj.o \
dbesj0.o dbesj1.o dbesk.o dbesk0.o dbesk1.o dbesks.o dbesy.o dbesy0.o \
dbesy1.o dbeta.o dbetai.o dbfqad.o dbhin.o dbi.o dbie.o dbinom.o \
dbint4.o dbintk.o dbkias.o dbkisr.o dbksol.o dbndac.o dbndsl.o \
dbnfac.o dbnslv.o dbocls.o dbols.o dbolsm.o dbsgq8.o dbsi0e.o dbsi1e.o \
dbsk0e.o dbsk1e.o dbskes.o dbskin.o dbsknu.o dbspdr.o dbspev.o \
dbsppp.o dbspvd.o dbspvn.o dbsqad.o dbsynu.o dbvalu.o dbvder.o \
dbvpor.o dbvsup.o dcbrt.o dcdot.o dcfod.o dcg.o dcgn.o dcgs.o dchdc.o \
dchdd.o dchex.o dchfcm.o dchfdv.o dchfev.o dchfie.o dchkw.o dchu.o \
dchud.o dckder.o dcoef.o dcopy.o dcopym.o dcosdg.o dcot.o dcov.o \
dcpplt.o dcscal.o dcsevl.o dcv.o ddaini.o ddajac.o ddanrm.o ddaslv.o \
ddassl.o ddastp.o ddatrp.o ddaws.o ddawts.o ddcor.o ddcst.o ddeabm.o \
ddebdf.o dderkf.o ddes.o ddntl.o ddntp.o ddoglg.o ddot.o ddpsc.o \
ddpst.o ddriv1.o ddriv2.o ddriv3.o ddscl.o ddstp.o ddzro.o de1.o \
deabm.o debdf.o defc.o defcmn.o defe4.o defehl.o defer.o dei.o \
denorm.o derf.o derfc.o derkf.o derkfs.o des.o dexbvp.o dexint.o \
dexprl.o dfac.o dfc.o dfcmn.o dfdjc1.o dfdjc3.o dfehl.o dfspvd.o \
dfspvn.o dfulmt.o dfzero.o dgami.o dgamic.o dgamit.o dgamlm.o dgamln.o \
dgamma.o dgamr.o dgamrn.o dgaus8.o dgbco.o dgbdi.o dgbfa.o dgbmv.o \
dgbsl.o dgeco.o dgedi.o dgefa.o dgefs.o dgemm.o dgemv.o dger.o dgesl.o \
dglss.o dgmres.o dgtsl.o dh12.o dhels.o dheqr.o dhfti.o dhkseq.o \
dhstrt.o dhvnrm.o dintp.o dintrv.o dintyd.o dir.o djairy.o dlbeta.o \
dlgams.o dli.o dllsia.o dllti2.o dlngam.o dlnrel.o dlpdoc.o dlpdp.o \
dlsei.o dlsi.o dlsod.o dlssud.o dmacon.o dmgsbv.o dmout.o dmpar.o \
dnbco.o dnbdi.o dnbfa.o dnbfs.o dnbsl.o dnls1.o dnls1e.o dnrm2.o \
dnsq.o dnsqe.o dogleg.o dohtrl.o domn.o dorth.o dorthr.o dp1vlu.o \
dpbco.o dpbdi.o dpbfa.o dpbsl.o dpchbs.o dpchce.o dpchci.o dpchcm.o \
dpchcs.o dpchdf.o dpchfd.o dpchfe.o dpchia.o dpchic.o dpchid.o \
dpchim.o dpchkt.o dpchng.o dpchsp.o dpchst.o dpchsw.o dpcoef.o \
dpfqad.o dpigmr.o dpincw.o dpinit.o dpintm.o dpjac.o dplint.o dplpce.o \
dplpdm.o dplpfe.o dplpfl.o dplpmn.o dplpmu.o dplpup.o dpnnzr.o dpoch.o \
dpoch1.o dpoco.o dpodi.o dpofa.o dpofs.o dpolcf.o dpolft.o dpolvl.o \
dpopt.o dposl.o dppco.o dppdi.o dpperm.o dppfa.o dppgq8.o dppqad.o \
dppsl.o dppval.o dprvec.o dprwpg.o dprwvr.o dpsi.o dpsifn.o dpsixn.o \
dpsort.o dptsl.o dqag.o dqage.o dqagi.o dqagie.o dqagp.o dqagpe.o \
dqags.o dqagse.o dqawc.o dqawce.o dqawf.o dqawfe.o dqawo.o dqawoe.o \
dqaws.o dqawse.o dqc25c.o dqc25f.o dqc25s.o dqcheb.o dqdota.o dqdoti.o \
dqelg.o dqform.o dqk15.o dqk15i.o dqk15w.o dqk21.o dqk31.o dqk41.o \
dqk51.o dqk61.o dqmomo.o dqnc79.o dqng.o dqpsrt.o dqrdc.o dqrfac.o \
dqrsl.o dqrslv.o dqwgtc.o dqwgtf.o dqwgts.o drc.o drc3jj.o drc3jm.o \
drc6j.o drd.o dreadp.o dreort.o drf.o drj.o drkfab.o drkfs.o drlcal.o \
drot.o drotg.o drotm.o drotmg.o drsco.o ds2lt.o ds2y.o dsbmv.o dscal.o \
dsd2s.o dsdbcg.o dsdcg.o dsdcgn.o dsdcgs.o dsdgmr.o dsdi.o dsdomn.o \
dsdot.o dsds.o dsdscl.o dsgs.o dsiccg.o dsico.o dsics.o dsidi.o \
dsifa.o dsilur.o dsilus.o dsindg.o dsisl.o dsjac.o dsli.o dsli2.o \
dsllti.o dslubc.o dslucn.o dslucs.o dslugm.o dslui.o dslui2.o dslui4.o \
dsluom.o dsluti.o dslvs.o dsmmi2.o dsmmti.o dsmtv.o dsmv.o dsort.o \
dsos.o dsoseq.o dsossl.o dspco.o dspdi.o dspenc.o dspfa.o dsplp.o \
dspmv.o dspr.o dspr2.o dspsl.o dsteps.o dstod.o dstor1.o dstway.o \
dsuds.o dsvco.o dsvdc.o dswap.o dsymm.o dsymv.o dsyr.o dsyr2.o \
dsyr2k.o dsyrk.o dtbmv.o dtbsv.o dtin.o dtout.o dtpmv.o dtpsv.o \
dtrco.o dtrdi.o dtrmm.o dtrmv.o dtrsl.o dtrsm.o dtrsv.o du11ls.o \
du11us.o du12ls.o du12us.o dulsia.o dusrmt.o dvecs.o dvnrms.o dvout.o \
dwnlit.o dwnlsm.o dwnlt1.o dwnlt2.o dwnlt3.o dwnnls.o dwritp.o \
dwupdt.o dx.o dx4.o dxadd.o dxadj.o dxc210.o dxcon.o dxlcal.o dxlegf.o \
dxnrmp.o dxpmu.o dxpmup.o dxpnrm.o dxpqnu.o dxpsi.o dxqmu.o dxqnu.o \
dxred.o dxset.o dy.o dy4.o dyairy.o e1.o efc.o efcmn.o ei.o eisdoc.o \
elmbak.o elmhes.o eltran.o enorm.o erf.o erfc.o exbvp.o exint.o \
exprel.o ezfft1.o ezfftb.o ezfftf.o ezffti.o fac.o fc.o fcmn.o \
fdjac1.o fdjac3.o fdump.o fftdoc.o figi.o figi2.o fulmat.o fundoc.o \
fzero.o gami.o gamic.o gamit.o gamlim.o gamln.o gamma.o gamr.o gamrn.o \
gaus8.o genbun.o h12.o hfti.o hkseq.o hpperm.o hpsort.o hqr.o hqr2.o \
hstart.o hstcrt.o hstcs1.o hstcsp.o hstcyl.o hstplr.o hstssp.o \
htrib3.o htribk.o htrid3.o htridi.o hvnrm.o hw3crt.o hwscrt.o hwscs1.o \
hwscsp.o hwscyl.o hwsplr.o hwsss1.o hwsssp.o i1mach.o i1merg.o \
icamax.o icopy.o idamax.o idloc.o imtql1.o imtql2.o imtqlv.o indxa.o \
indxb.o indxc.o initds.o inits.o intrv.o intyd.o invit.o inxca.o \
inxcb.o inxcc.o iploc.o ipperm.o ipsort.o isamax.o isdbcg.o isdcg.o \
isdcgn.o isdcgs.o isdgmr.o isdir.o isdomn.o isort.o issbcg.o isscg.o \
isscgn.o isscgs.o issgmr.o issir.o issomn.o iswap.o ivout.o j4save.o \
jairy.o la05ad.o la05as.o la05bd.o la05bs.o la05cd.o la05cs.o la05ed.o \
la05es.o llsia.o lmpar.o lpdp.o lsame.o lsei.o lsi.o lsod.o lssods.o \
lssuds.o macon.o mc20ad.o mc20as.o mgsbv.o minfit.o minso4.o minsol.o \
mpadd.o mpadd2.o mpadd3.o mpblas.o mpcdm.o mpchk.o mpcmd.o mpdivi.o \
mperr.o mpmaxr.o mpmlp.o mpmul.o mpmul2.o mpmuli.o mpnzr.o mpovfl.o \
mpstr.o mpunfl.o numxer.o ohtrol.o ohtror.o ortbak.o orthes.o ortho4.o \
orthog.o orthol.o orthor.o ortran.o passb.o passb2.o passb3.o passb4.o \
passb5.o passf.o passf2.o passf3.o passf4.o passf5.o pchbs.o pchce.o \
pchci.o pchcm.o pchcs.o pchdf.o pchdoc.o pchfd.o pchfe.o pchia.o \
pchic.o pchid.o pchim.o pchkt.o pchngs.o pchsp.o pchst.o pchsw.o \
pcoef.o pfqad.o pgsf.o pimach.o pinitm.o pjac.o pnnzrs.o poch.o \
poch1.o pois3d.o poisd2.o poisn2.o poisp2.o poistg.o polcof.o polfit.o \
polint.o polyvl.o pos3d1.o postg2.o ppadd.o ppgq8.o ppgsf.o pppsf.o \
ppqad.o ppsgf.o ppspf.o ppval.o proc.o procp.o prod.o prodp.o prvec.o \
prwpge.o prwvir.o psgf.o psi.o psifn.o psixn.o pvalue.o pythag.o qag.o \
qage.o qagi.o qagie.o qagp.o qagpe.o qags.o qagse.o qawc.o qawce.o \
qawf.o qawfe.o qawo.o qawoe.o qaws.o qawse.o qc25c.o qc25f.o qc25s.o \
qcheb.o qelg.o qform.o qk15.o qk15i.o qk15w.o qk21.o qk31.o qk41.o \
qk51.o qk61.o qmomo.o qnc79.o qng.o qpdoc.o qpsrt.o qrfac.o qrsolv.o \
qs2i1d.o qs2i1r.o qwgtc.o qwgtf.o qwgts.o qzhes.o qzit.o qzval.o \
qzvec.o r1mach.o r1mpyq.o r1updt.o r9aimp.o r9atn1.o r9chu.o r9gmic.o \
r9gmit.o r9knus.o r9lgic.o r9lgit.o r9lgmc.o r9ln2r.o r9pak.o r9upak.o \
radb2.o radb3.o radb4.o radb5.o radbg.o radf2.o radf3.o radf4.o \
radf5.o radfg.o rand.o ratqr.o rc.o rc3jj.o rc3jm.o rc6j.o rd.o \
rebak.o rebakb.o reduc.o reduc2.o reort.o rf.o rfftb.o rfftb1.o \
rfftf.o rfftf1.o rffti.o rffti1.o rg.o rgauss.o rgg.o rj.o rkfab.o \
rpqr79.o rpzero.o rs.o rsb.o rsco.o rsg.o rsgab.o rsgba.o rsp.o rst.o \
rt.o runif.o rwupdt.o s1merg.o sasum.o saxpy.o sbcg.o sbhin.o sbocls.o \
sbols.o sbolsm.o scasum.o scg.o scgn.o scgs.o schdc.o schdd.o schex.o \
schkw.o schud.o sclosm.o scnrm2.o scoef.o scopy.o scopym.o scov.o \
scpplt.o sdaini.o sdajac.o sdanrm.o sdaslv.o sdassl.o sdastp.o \
sdatrp.o sdawts.o sdcor.o sdcst.o sdntl.o sdntp.o sdot.o sdpsc.o \
sdpst.o sdriv1.o sdriv2.o sdriv3.o sdscl.o sdsdot.o sdstp.o sdzro.o \
sepeli.o sepx4.o sgbco.o sgbdi.o sgbfa.o sgbmv.o sgbsl.o sgeco.o \
sgedi.o sgeev.o sgefa.o sgefs.o sgeir.o sgemm.o sgemv.o sger.o sgesl.o \
sglss.o sgmres.o sgtsl.o shels.o sheqr.o sindg.o sinqb.o sinqf.o \
sinqi.o sint.o sinti.o sintrp.o sir.o sllti2.o slpdoc.o slvs.o smout.o \
snbco.o snbdi.o snbfa.o snbfs.o snbir.o snbsl.o snls1.o snls1e.o \
snrm2.o snsq.o snsqe.o sods.o somn.o sopenm.o sorth.o sos.o soseqs.o \
sossol.o spbco.o spbdi.o spbfa.o spbsl.o speli4.o spelip.o spenc.o \
spigmr.o spincw.o spinit.o splp.o splpce.o splpdm.o splpfe.o splpfl.o \
splpmn.o splpmu.o splpup.o spoco.o spodi.o spofa.o spofs.o spoir.o \
spopt.o sposl.o sppco.o sppdi.o spperm.o sppfa.o sppsl.o spsort.o \
sptsl.o sqrdc.o sqrsl.o sreadp.o srlcal.o srot.o srotg.o srotm.o \
srotmg.o ss2lt.o ss2y.o ssbmv.o sscal.o ssd2s.o ssdbcg.o ssdcg.o \
ssdcgn.o ssdcgs.o ssdgmr.o ssdi.o ssdomn.o ssds.o ssdscl.o ssgs.o \
ssiccg.o ssico.o ssics.o ssidi.o ssiev.o ssifa.o ssilur.o ssilus.o \
ssisl.o ssjac.o ssli.o ssli2.o ssllti.o sslubc.o sslucn.o sslucs.o \
sslugm.o sslui.o sslui2.o sslui4.o ssluom.o ssluti.o ssmmi2.o ssmmti.o \
ssmtv.o ssmv.o ssort.o sspco.o sspdi.o sspev.o sspfa.o sspmv.o sspr.o \
sspr2.o sspsl.o ssvdc.o sswap.o ssymm.o ssymv.o ssyr.o ssyr2.o \
ssyr2k.o ssyrk.o stbmv.o stbsv.o steps.o stin.o stod.o stor1.o stout.o \
stpmv.o stpsv.o strco.o strdi.o strmm.o strmv.o strsl.o strsm.o \
strsv.o stway.o suds.o svco.o svd.o svecs.o svout.o swritp.o sxlcal.o \
tevlc.o tevls.o tinvit.o tql1.o tql2.o tqlrat.o trbak1.o trbak3.o \
tred1.o tred2.o tred3.o tri3.o tridib.o tridq.o tris4.o trisp.o trix.o \
tsturm.o u11ls.o u11us.o u12ls.o u12us.o ulsia.o usrmat.o vnwrms.o \
wnlit.o wnlsm.o wnlt1.o wnlt2.o wnlt3.o wnnls.o xadd.o xadj.o xc210.o \
xcon.o xerbla.o xerclr.o xercnt.o xerdmp.o xerhlt.o xermax.o xermsg.o \
xerprn.o xersve.o xgetf.o xgetua.o xgetun.o xlegf.o xnrmp.o xpmu.o \
xpmup.o xpnrm.o xpqnu.o xpsi.o xqmu.o xqnu.o xred.o xset.o xsetf.o \
xsetua.o xsetun.o yairy.o zabs.o zacai.o zacon.o zairy.o zasyi.o \
zbesh.o zbesi.o zbesj.o zbesk.o zbesy.o zbinu.o zbiry.o zbknu.o \
zbuni.o zbunk.o zdiv.o zexp.o zkscl.o zlog.o zmlri.o zmlt.o zrati.o \
zs1s2.o zseri.o zshch.o zsqrt.o zuchk.o zunhj.o zuni1.o zuni2.o \
zunik.o zunk1.o zunk2.o zuoik.o zwrsk.o

lib$(LIB):	$(OBJ)
	@$(LIBTOOL) --mode=link $(FORTRAN) -O -o lib$(LIB).la $(OBJ:.o=.lo) \
	-rpath $(LIBDIR)

.f.o:
	@$(LIBTOOL) --mode=compile $(FORTRAN) $(FFLAGS) -c $*.f

install:
	@$(LIBTOOL) --mode=install install lib$(LIB).la $(LIBDIR)

clean:
	rm -rf *.o *.lo .libs lib$(LIB).la
