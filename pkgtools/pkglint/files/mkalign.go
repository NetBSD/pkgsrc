package pkglint

type MkAlignFile struct {
	Paras []*MkAlignPara
}

func (f *MkAlignFile) AlignParas() {
	//  #.  Ein einzelner Absatz, der einen Tab weniger eingerückt ist als die übrigen,
	//      darf auf die Einrückung der anderen Absätze angeglichen werden,
	//      sofern der Absatz dadurch nicht zu breit wird.
	panic("implement me")
}

type MkAlignPara struct {
}

func (p *MkAlignPara) IsAligned() bool {
	//  #.  Das Ausrichten mit mehr als 1 Tab ist erlaubt, wenn die Ausrichtung einheitlich ist.

	//  #.  Wenn VarOp über die Ausrichtung hinausragt (Ausreißer),
	//      darf zwischen VarOp und Wert statt der Ausrichtung 1 Leerzeichen sein.

	//  #.  Das Verhältnis zwischen Tab-Zeilen und hinausragenden Zeilen muss ausgewogen sein.
	//      Nicht zu viele hinausragende Zeilen. (Noch zu definieren.)
	//      Möglicher Ansatz: Anteil der Leerfläche?

	panic("implement me")
}

func (p *MkAlignPara) IsOutlier(line *MkAlignLine) bool {
	//  #.  Wenn VarOp über die Ausrichtung hinausragt (Ausreißer),
	//      darf zwischen VarOp und Wert statt der Ausrichtung 1 Leerzeichen sein.
	panic("implement me")
}

// ValueAlignment returns the column at which all values of the paragraph
// are aligned, or false if they aren't.
//
//  #.  Die Werte aller Zeilen sind mit Tabs an einer gemeinsamen vertikalen Linie
//      (Ausrichtung) ausgerichtet.
func (p *MkAlignPara) ValueAlignment() (bool, int) {
	panic("implement me")
}

func (p *MkAlignPara) MinValueAlignment() int {
	//  #.  Die minimale Ausrichtung ergibt sich aus der maximalen Breite von # und VarOp
	//      aller Zeilen, gerundet zum nächsten Tabstopp.
	//      Dabei zählen auch Zeilen mit, die rechts von VarOp komplett leer sind.
	panic("implement me")
}

func (p *MkAlignPara) MaxValueAlignment() int {
	//  #.  Die maximale Ausrichtung ergibt sich aus der maximalen Breite von Wert
	//      und Kommentar, abgezogen vom maximalen rechten Rand (in Spalte 73).
	panic("implement me")
}

func (p *MkAlignPara) MayAlignValuesTo(column int) bool {
	panic("implement me")
}

func (p *MkAlignPara) AlignValuesTo(column int) {
	//  #.  Beim Umformatieren darf die Zeilenbreite die 73 Zeichen nicht überschreiten,
	//      damit am rechten Rand eindeutig ist, wo jede Zeile aufhört.
	//      Zeilen, die bereits vorher breiter waren, dürfen ruhig noch breiter werden.

	panic("implement me")
}

type MkAlignMkLine struct {
}

func (l *MkAlignMkLine) RightMargin() int {
	//  #.  Jede MkZeile hat für alle ihre Zeilen einen gemeinsamen rechten Rand.

	//  #.  Um den gemeinsamen rechten Rand zu bestimmen, werden alle Zeilen ignoriert,
	//      in denen die Fortsetzung durch 1 Leerzeichen abgetrennt ist.

	//  #.  Einzelne Fortsetzungen dürfen über den rechten Rand hinausragen.
	//      Die Fortsetzung wird dann durch 1 Leerzeichen abgetrennt.

	panic("implement me")
}

func (l *MkAlignMkLine) IsCanonical() bool {
	//  #.  Eine leere Erstzeile mit 1 fortgesetzer Zeile ist nur zulässig,
	//      wenn die kombinierte Zeile breiter als 73 Zeichen wäre.
	//      Sonst werden die beiden Zeilen kombiniert.

	//  ### Mehrzeilig, fortgesetzte Zeilen
	//
	//  #.  Nach einer leeren Erstzeile ist die erste fortgesetzte Zeile an der
	//      Ausrichtung aller Zeilen eingerückt, wenn die Erstzeile über die
	//      Ausrichtung ragt und der Platz aller Zeilen es zulässt, andernfalls
	//      mit 1 Tab.
	//
	//  #.  Bei mehrzeiligen einrückbaren Werten (AWK, Shell, Listen aus Tupeln)
	//      dürfen die weiteren Fortsetzungszeilen weiter eingerückt sein als die erste.
	//      Ihre Einrückung besteht aus Tabs, gefolgt von 0 bis 7 Leerzeichen.

	// In the continuation lines, each follow-up line is indented with at least
	// one tab, to avoid confusing them with regular single-lines. This is
	// especially true for CONFIGURE_ENV, since the environment variables are
	// typically uppercase as well.

	//  MULTI_LINE= \
	//          The value starts in the second line.
	//
	// The backslash in the first line is usually aligned to the other variables
	// in the same paragraph. If the variable name is longer than the indentation
	// of the paragraph, it may be indented with a single space.
	//
	// In multi-line shell commands or AWK programs, the backslash is
	// often indented to column 73, as are the backslashes from the follow-up
	// lines, to act as a visual guideline.

	// Continuation lines may or may not have their value in the first line.

	// In general, all values should be aligned using tabs.
	// As an exception, a single very long line (called an outlier) may be
	// aligned with a single space.
	// A typical example is a SITES.very-long-file-name.tar.gz variable
	// between HOMEPAGE and DISTFILES.

	panic("implement me")
}

func (l *MkAlignMkLine) HasCanonicalRightMargin() bool {
	//  #.  Die Fortsetzungen jeder MkZeile sind entweder alle durch je 1 Leerzeichen abgetrennt,
	//      oder alle Fortsetzungen sind am rechten Rand.

	//  #.  Einzelne Fortsetzungen dürfen über den rechten Rand hinausragen.
	//      Die Fortsetzung wird dann durch 1 Leerzeichen abgetrennt.

	//  #.  Die Fortsetzung der Erstzeile mit Wert ist durch 1 Leerzeichen abgetrennt,
	//      wenn sie rechts von der Ausrichtung steht,
	//      andernfalls durch Tabs an der Ausrichtung.

	panic("implement me")
}

func (l *MkAlignMkLine) CurrentValueAlign() int {
	// The indentation of the first value of the variable determines the minimum
	// indentation for the remaining continuation lines.
	//
	// To allow long variable
	// values to be indented as little as possible, the follow-up lines only need
	// to be indented by a single tab, even if the other
	// variables in the paragraph are aligned further to the right.
	//
	// If the
	// indentation is not a single tab, it must match the indentation of the
	// other lines in the paragraph.
	panic("implement me")
}

type MkAlignLine struct {
	Comment          string
	VarOp            string
	SpaceBeforeValue string
	Value            string
	SpaceAfterValue  string
	Continuation     string
}

func (l *MkAlignLine) HasCanonicalRightMargin(valueAlignColumn int) bool {
	panic("implement me")
}

func (l *MkAlignLine) IsCanonicalSingle() bool {
	panic("implement me")
}

func (l *MkAlignLine) IsCanonicalLeadEmpty() bool {
	//  SHELL_CMD=                                                              \
	//          if ${PKG_ADMIN} pmatch ${PKGNAME} ${dependency}; then           \
	//                  ${ECHO} yes;                                            \
	//          else                                                            \
	//                  ${ECHO} no;                                             \
	//          fi
	//
	//
	panic("implement me")
}

func (l *MkAlignLine) IsCanonicalLeadValue() bool {
	//  MULTI_LINE=     The value starts in the first line \
	//                  and continues in the second line.
	//
	// In lists or plain text, like in the example above, all values are
	// aligned in the same column. Some variables also contain code, and in
	// these variables, the line containing the first word defines how deep
	// the follow-up lines must be indented at least.

	panic("implement me")
}

func (l *MkAlignLine) IsCanonicalFollowLead() bool {
	//  SHELL_CMD=                                                              \
	// -->      if ${PKG_ADMIN} pmatch ${PKGNAME} ${dependency}; then           \
	//                  ${ECHO} yes;                                            \
	//          else                                                            \
	//                  ${ECHO} no;                                             \
	//          fi
	//
	//  MULTI_LINE=     The value starts in the first line \
	//                  and continues in the second line.
	//
	// In lists or plain text, like in the example above, all values are
	// aligned in the same column. Some variables also contain code, and in
	// these variables, the line containing the first word defines how deep
	// the follow-up lines must be indented at least.

	panic("implement me")
}

func (l *MkAlignLine) IsCanonicalFollow() bool {
	// In the continuation lines, each follow-up line is indented with at least
	// one tab, to avoid confusing them with regular single-lines. This is
	// especially true for CONFIGURE_ENV, since the environment variables are
	// typically uppercase as well.

	//  SHELL_CMD=                                                              \
	//          if ${PKG_ADMIN} pmatch ${PKGNAME} ${dependency}; then           \
	//                  ${ECHO} yes;                                            \
	//          else                                                            \
	//                  ${ECHO} no;                                             \
	//          fi
	//
	//

	panic("implement me")
}
