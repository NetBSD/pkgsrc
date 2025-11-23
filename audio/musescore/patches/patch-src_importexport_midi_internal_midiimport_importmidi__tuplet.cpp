$NetBSD: patch-src_importexport_midi_internal_midiimport_importmidi__tuplet.cpp,v 1.1 2025/11/23 03:20:56 gutteridge Exp $

Fix building with Qt 6.10.

--- src/importexport/midi/internal/midiimport/importmidi_tuplet.cpp.orig	2025-10-21 08:21:23.000000000 +0000
+++ src/importexport/midi/internal/midiimport/importmidi_tuplet.cpp
@@ -895,9 +895,9 @@ void addTupletEvents(std::multimap<Reduc
                 message += QString::number(tiedTuplet.voice) + ", chord voice = ";
                 message += QString::number(midiChord.voice) + ", bar number (from 1) = ";
                 message += QString::number(midiChord.barIndex + 1);
-#endif
                 Q_ASSERT_X(tiedTuplet.voice == midiChord.voice,
                            "MidiTuplet::addTupletEvents", message.toLatin1().data());
+#endif
 
                 for (int j: tiedTuplet.tiedNoteIndexes) {
                     midiChord.notes[j].tuplet = it;
