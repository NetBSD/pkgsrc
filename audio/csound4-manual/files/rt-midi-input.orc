# use: csound -o /dev/sound -M /dev/rmidi1 rt-midi-input.orc rt-midi-input.sco
#
# you may need to use /dev/rmidi0 instead

instr 1
inum notnum ; note number
kfreq cpsmidib ; MIDI to frequency
iamp ampmidi inum*100  ; MIDI to amplitude
                       ; (scaled within range)
if inum > 60 goto fun1 ; if the MIDI note number
                       ; is over 60...
if inum < 61 goto fun2 ; if the note number is 
                       ; less than 61...
fun1:
ifn = 1
 goto contin
fun2:
ifn = 2
 goto contin
contin:
asig oscil iamp,kfreq,ifn
 out asig
 endin
